#include<iostream>
#include<String>
#include<stdlib.h>
#include<time.h>
using namespace std;

class crewMember
{
private:
	string name;
	signed int affection;
public:
	void talkTo();
	void assignName(string crewName);
	int currentRoom;
};

void crewMember::talkTo()
{
	if (crewMember::name == "Krystal")
		cout<<"Why, hello there stranger.\n";
	else if (crewMember::name == "Falco")
		cout<<"Who the hell are you??\n";
	else if (crewMember::name == "Peppy")
		cout<<"Greetings, young one.\n";
}
void crewMember::assignName(string crewName)
{
	name = crewName;
}

void welcomePlayer();
string getName();
void greetingName(string name);
void roomDescription(int currentRoom);
int changeRooms(string option, int currentRoom);
int moveOption(int currentRoom, string option);
int checkRoom(int currentRoom);
void startConversation();
void hangerDescription();
void hallADescription();
void hallA1Description();
void bridgeDescription();
void krysDoorDescription();
void foxDoorDescription();
int const HANGER = 1;
int const HALLA = 2;
int const HALLA1 = 3;
int const BRIDGE = 4;
int const KRYSDOOR = 5;
int const FOXDOOR = 6;
int main()
{
	int currentRoom = HANGER;
	string option;
	welcomePlayer();
	string Name= getName();
	greetingName(Name);
	
	while (true)
	{
		if (option == "quit")
			break;
		roomDescription(currentRoom);
		cin>>option;
		if (option == "w" || option == "e" || option == "n" || option == "s")
		{currentRoom = changeRooms(option, currentRoom);}
		if (option == "talk")
			startConversation();
		if (option == "room")
			cout<<checkRoom(currentRoom);
	}
	return 0;
}

void welcomePlayer()
{
	cout<<"Hello! Welcome to the world of StarFox!\n";
	cout<<"Let's go on an adventure, exploring the Great Fox.\n\n";
	cout<<"Type in the letter of the direction you would like to go\n N= north, E= east and so on.\n\n";
	cout<<"What are you waiting for? let's get right into it.\n\n";
}
string getName()
{
	string playerName;
	cout<<"\n\n Enter your name: ";
	cin>>playerName;
	return playerName;
}
void greetingName(string playerName)
{
	if (playerName == "Fox")
	{
		cout<<"You wanna play as Fox huh?\n Ok, you can be StarFox's fearless leader.\n\n";
	}
	else if (playerName == "Falco")
	{
		cout<<"You wanna be StarFox's ace pilot?\n Well, he is quite the character\n\n"; 
	}
	else
	{
		cout<<"\nAlright nice to meet you,"<<playerName<<"\n\n";
	}
}
void roomDescription(int currentRoom)
{
	if (currentRoom == HANGER)
	{
		hangerDescription();
	}
	else if (currentRoom == HALLA)
	{
		hallADescription();
	}
	else if (currentRoom == HALLA1)
		hallA1Description();
	else if(currentRoom == KRYSDOOR)
		krysDoorDescription();
	else if(currentRoom == BRIDGE)
		bridgeDescription();
	else if(currentRoom == FOXDOOR)
		foxDoorDescription();
}
int changeRooms(string option, int currentRoom)
{
	int choice = moveOption(currentRoom, option);
	return choice;
}
int moveOption(int currentRoom, string option)
{
	while (currentRoom == HANGER)
	{
	  if (option == "w")
		  return HALLA;
	  else
	  {cout<<"Sorry, that'a an invalid option. \n\n Try again: ";
	  cin>>option;}
	    
	}
	while (currentRoom == HALLA)
	{
		if (option == "e")
			return HANGER;
		else if (option == "n")
			return HALLA1;
		else
	  {cout<<"Sorry, that'a an invalid option. \n\n Try again: ";
	  cin>>option;}
		
	}
	while (currentRoom == HALLA1)
	{
		if (option == "s")
			return HALLA;
		else if (option == "n")
			return BRIDGE;
		else if (option == "e")
			return KRYSDOOR;
		else if (option == "w")
			return FOXDOOR;
		else 
			{cout<<"Sorry, that'a an invalid option. \n\n Try again: ";
	  cin>>option;}
	}
	while (currentRoom == BRIDGE)
		{if (option == "s")
			return HALLA1;
		else 
			{cout<<"Sorry, that'a an invalid option. \n\n Try again: ";
	  cin>>option;}
	}
	while (currentRoom == FOXDOOR)
	{
		if (option == "e")
			return HALLA1;
		else
			{cout<<"Sorry, that'a an invalid option. \n\n Try again: ";
	  cin>>option;}
	}
	while (currentRoom == KRYSDOOR)
	{
		if (option == "w")
			return HALLA1;
		else
			{cout<<"Sorry, that'a an invalid option. \n\n Try again: ";
	  cin>>option;}
	}
}
void startConversation()
{
	int currentRoom = checkRoom(currentRoom);
}
int checkRoom(int currentRoom)
{
	return currentRoom;
}
void hangerDescription()
{
	cout<<"\nYou're standing in the hanger of the GreatFox. Metal walls surround you.\n There are four advanced fighter jets sitting little bit away.\n There is a door to your left, leading deeper into the ship.\n (West)";
}
void hallADescription()
{
	cout<<"You are now standing in a long hallway, there are doors lining the hall,\n each with diffrent names printed on them.\nThe entrance to the hanger is behind you. \n(North, East)";
}
void hallA1Description()
{
	cout<<"You move down the hall passing by doors on your left and right.\n(South, North, East, West)";
}
void bridgeDescription()
{
	crewMember Krystal;
	Krystal.assignName("Krystal");
	Krystal.currentRoom = 4;
	if (Krystal.currentRoom == 4)
	{
		cout<<"You see a beautiful blue fox standing on the bridge.\n(Talk, South)";
	}
	else
		cout<<"You are on the bridge.\n(South)";
}
void krysDoorDescription()
{
	cout<<"You're now standing infront of a door labeled 'Krystal'\n (West)";
}
void foxDoorDescription()
{
	cout<<"You're now standing infront of a door labeled 'Fox'\n(East)";
}
