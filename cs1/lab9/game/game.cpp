// This is a Battleship game using classes
// Michael Lovell
// CS13012-005
// 11/12/2015

#include <iostream>
#include "battleship.h"

using std::cout; using std::cin; using std::endl;

int main(){
	fleet myfleet;
	char answer;
	myfleet.deployFleet();
	cout << "Do you need to see the position and status of my fleet's ships? enter y or n" << endl;
	cin >> answer;
	if (answer == 'y')
		myfleet.printFleet();
	while (myfleet.operational())
	{
		location attackLoc;
		attackLoc.fire();
		myfleet.isHitNSink(attackLoc);
		if (myfleet.isHitNSink(attackLoc))
			cout << "it's a hit" << endl;
		if (!myfleet.isHitNSink(attackLoc))
			cout << "it's a miss" << endl;
		myfleet.printFleet();

	}

	cout << "You've sunk my whole fleet!" << endl;
}
