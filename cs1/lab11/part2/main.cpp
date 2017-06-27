// This file holds the functions used in the program
// Michael Lovell
// 13012-005
// 11/15/2015

#include <iostream>
#include "vararray.h"

using std::cout; using std::cin; using std::endl;

int main(){
	char operation = 'c';
	int number;
	varArray userArray;
	do
	{
		cout << "Enter operation [a/r/q] and number: " << endl;
		cin >> operation;
		if (operation == 'q')
			break;
		cin >> number;
		if (operation == 'a')
			userArray.addNumber(number);
		if (operation == 'r')
			userArray.removeNumber(number);
		userArray.output();
	} while (operation != 'q');
}
