// This file holds the functions used in the program
// Michael Lovell
// 13012
// 11/15/2015

#include <iostream>
#include "varArray.h"

using std::cout; using std::cin; using std::endl;

int main(){
	char operation = 'c';
	int number;
	int size = 0;  // setting array size
	int *a = new int[size]; // allocating dynamic array

	do
	{
		cout << "Enter operation [a/r/q] and number:" << endl;
		cin >> operation;
		if (operation == 'q')
			break;
		cin >> number;
		if (operation == 'a')
			addNumber(a, number, size);
		if (operation == 'r')
			removeNumber(a, number, size);
		output(a, size);

	} while (operation != 'q');
	delete[] a; // deallocating the array
}
