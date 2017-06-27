// This file contains the functions needed for my battleship game.
// Michael Lovell
// CS
// 11/2/2015

#include "battleship.h"
#include <iostream>
#include <ctime>

using std::cout; using std::cin; using std::endl;

// while # of deployed ships is less than 5 
// random # selected and compared against other assigned locations in array
// the the random # is unique it is assigned to the current element and function moves to the next iteration
// if the random # is not unique the random number generator is re-executed
void deploy(struct ship myship[]){
	srand(time(nullptr));
	location pick_holder;
	int deployed_ships = 0;
	while (deployed_ships < FLEET_SIZE)
	{
		pick_holder = pick();
		if (check(myship, pick_holder) == -1){ // -1 is the initialized x value
			myship[deployed_ships].loc.x = pick_holder.x;
			myship[deployed_ships].loc.y = pick_holder.y;
			deployed_ships++;
		}
	}
}

// starting value for each stucture member is assigned
void initialize(struct ship myship[]){
	for (int i = 0; i < FLEET_SIZE; i++)
	{
		myship[i].loc.x = -1;
		myship[i].loc.y = '*';
		myship[i].sunk = false;
	}
}

// ship status output function
void printShip(struct ship myship){
	cout << "The ship is at " << myship.loc.x << myship.loc.y << endl;
	if (myship.sunk == false)
		cout << "and it's still afloat!" << endl;
	if (myship.sunk == true)
		cout << "You've sunk a battleship!" << endl;
}

// fleet status output fuction
void printFleet(const ship myship[]){
	for (int i = 0; i < FLEET_SIZE; i++)
		cout << "Ship" << i + 1 << " is at location " << myship[i].loc.x << myship[i].loc.y << endl;
}

// random location generator for the deploy function
location pick(){
	int y_holder;
	location toreturn;
	toreturn.x = (rand() % FLEET_SIZE) + 1;
	y_holder = rand() % FLEET_SIZE + 1;
	switch (y_holder){
	case 1:
		toreturn.y = 'a';
		break;
	case 2:
		toreturn.y = 'b';
		break;
	case 3:
		toreturn.y = 'c';
		break;
	case 4:
		toreturn.y = 'd';
		break;
	case 5:
		toreturn.y = 'e';
	}
	return toreturn;
}

// attack location specified by user
location fire(){
	location returnlocation;	
	cout << "to attack a ship type a number 1 thru 5 and a letter a thru e, like '5c'" << endl;
	cin >> returnlocation.x >> returnlocation.y;
	return returnlocation;
}

// function returns true if 2 locations match
bool match(ship myship, location mylocation){
	if ((myship.loc.x == mylocation.x) && (myship.loc.y == mylocation.y))
		return true;
	else
		return false;
}
