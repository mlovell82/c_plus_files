// This program is a battleship game
// Michael Lovell
// CS 13012-005
// 11/06/2015

#include <iostream>
#include "battleship.h"

using std::cout; using std::cin; using std::endl;

int main(){

	// creates a fleet of 5 ships & sets starting values for the fleets 5 ships
	ship myships[FLEET_SIZE];
	initialize(myships);

	// places the ships of the fleet in random locations in the ocean
	deploy(myships);

	// game lasts while all ships are operational
	while (operational(myships)){
		location attack = fire();
		int shot = check(myships, attack);
		if (shot >= 0){
			sink(myships[shot]);
			cout << "You've sunk a ship" << endl;
			printShip(myships[shot]);			
		}
		else
			cout << "That's a miss" << endl;
	}
	cout << "Egad, you've sunk the fleet!" << endl;
}
