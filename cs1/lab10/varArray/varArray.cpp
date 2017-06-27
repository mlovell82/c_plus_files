// This file holds the functions used in the program
// Michael Lovell
// 13012
// 11/15/2015

#include <iostream>
#include "varArray.h"

using std::cout; using std::cin; using std::endl;

void output(int *arrayPtr, int size){
	for (int i = 0; i < size; i++)
		cout << arrayPtr[i] << " ";
	cout << endl;
}

int check(int *arrayPtr, int number, int size){
	int i;
	for (i = 0; i < size; i++){
		if (arrayPtr[i] == number)
			return i;
	}
	if (i == size)
		return -1;
}


// If number is not in array then size is incremented by 1 and element from old array is copied in new array
// Then element at size-1 is assigned the added number
void addNumber(int *& arrayPtr, int number, int &size){
	int added = check(arrayPtr, number, size);
	if (added == -1){
		++size;
		int *arrayPtr2 = new int[size];
		for (int i = 0; i < (size - 1); i++)
			arrayPtr2[i] = arrayPtr[i];
		arrayPtr2[size - 1] = number;
		delete[] arrayPtr;
		arrayPtr = arrayPtr2;
	}
	if (added != -1)
		cout << number << " already exists in array" << endl;
}

// If bool variable "found" is false function just copies one dyn array to the other
// If "found is true and element does not match "number" function copies dyn array to other at indes i-1
// then size is set to size-1
void removeNumber(int *& arrayPtr, int number, int &size){
	bool found = false;
	int *arrayPtr2 = new int[size - 1];
	for (int i = 0; i < size; i++){
		if ((arrayPtr[i] == number))
			found = true;
		if (!found)
			arrayPtr2[i] = arrayPtr[i];
		if ((found) && (arrayPtr[i] != number))
			arrayPtr2[i - 1] = arrayPtr[i];

	}
	if (found)
		--size;
	delete[] arrayPtr;
	arrayPtr = arrayPtr2;
}
