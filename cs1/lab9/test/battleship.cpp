
#include<iostream>
#include"battleship.h"
#include<ctime>

using std::cout; using std::cin; using std::endl;

location::location(){

	x = -1;
	y = '*';
}

void location::pick(){
	location temp;
	x = rand() % 5 + 1;
	int yholder = rand() % 5 + 1;
	switch (yholder){
	case 1:
		y = 'a';
		break;
	case 2:
		y = 'b';
		break;
	case 3:
		y = 'c';
		break;
	case 4:
		y = 'd';
		break;
	case 5:
		y = 'e';
		break;
	}

}

void location::fire(){
	cout << "Fire a shot at a battleship by entering";
	cout << "a number of 1 thru 5 and a letter of a thru e" << endl;

	cin >> x >> y;
}

void location::print()const{
	cout << y << x;
}

bool compare(location thisLoc, location thatLoc){
	bool result;
	if ((thisLoc.x == thatLoc.x) && (thisLoc.y == thatLoc.y)){
		result = true;
	}
	else{
		result = false;
	}
	return result;
}

ship::ship(){
	sunk = false;
}

bool ship::match(location& thisLoc)const{
	bool result = compare(thisLoc, loc);
	return result;

}



void ship::sink(){
	sunk = true;
}

void ship::setLocation(const location& thisLoc){

	for (int i = 0; i < 5; i++){
		loc = thisLoc;
	}

}

void ship::printShip()const{

	if (isSunk()){

		loc.print();
		cout << "Battle ship sunk" << endl;
	}
	if (!isSunk()){
		loc.print();
		cout << "Battle ship is not sunk" << endl;
	}
}

void fleet::deployFleet(){
	srand(time(nullptr));
	int deployedShips = 0;
	location locholder;
	while (deployedShips < fleetSize){
		locholder.pick();
		if (check(locholder) == -1){
			ships[deployedShips].setLocation(locholder);
			deployedShips++;
		}
	}
}

bool fleet::operational()const{
	for (int i = 0; i < fleetSize; i++){
		if (ships[i].isSunk() == false){
			return true;
			break;
		}
	}
	return false;
}

bool fleet::isHitNSink(const location& thisLoc){
	for (int i = 0; i < fleetSize; i++){
		if (check(thisLoc) != -1){
			ships[i].sink();
			return true;
			break;
		}
	}
	return false;

}

void fleet::printFleet()const{
	for (int i = 0; i < fleetSize; i++)
		ships[i].printShip();
}

int fleet::check(const location& thisLoc)const{
	location temploc = thisLoc;
	for (int i = 0; i < fleetSize; i++){
		if (ships[i].match(temploc)){
			return i;
			break;
		}

	}
	return -1;
}
