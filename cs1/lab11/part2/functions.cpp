// This file contains the functions for Lab11
// Michael Lovell
// CS13012
// 12/3/2015

#include "vararray.h"
#include <iostream>
using std::cout; using std::endl; using std::cin;

// Functions very identical to last weeks except for this void constructor and my big 3 functions
varArray::varArray(){
	dArray = new int[size];
}

int varArray::check(int number){
	int i;
	for (i = 0; i < size; ++i)
		if (dArray[i] == number){
			return i;
		}	
		return -1;
}

void varArray::addNumber(int a){
	if (check(a) < 0){
		int *d2Array = new int[size + 1];
		++size;
		for (int i = 0; i < (size - 1); ++i)
			d2Array[i] = dArray[i];
		d2Array[size - 1] = a;
		delete[] dArray;
		dArray = d2Array;
	}
}

void varArray::removeNumber(int a){
	bool found = false;
	if (check(a) > 0){
		int *d2Array = new int[size - 1];
		for (int i = 0; i < size; ++i){
			if ((dArray[i] == a))
				found = true;
			if (!found)
				d2Array[i] = dArray[i];
			if ((found) && (dArray[i] != a))
				d2Array[i - 1] = dArray[i];
		}
		if (found){
			--size;
			delete[] dArray;
			dArray = d2Array;
		}
	}
}

void varArray::output(){
	for (int i = 0; i < size; ++i)
		cout << dArray[i] << ' ';
}

// My big 3 "obj" used as paramater variable for class objects
varArray::varArray(const varArray& obj){
	size = obj.size;
	dArray = new int[size];
	for (int i = 0; i < size; ++i) dArray[i] = obj.dArray[i];
}

varArray& varArray::operator= (const varArray& obj){
	if (this != &obj){
		size = obj.size;
		delete[] dArray;
		dArray = new int[size];
		for (int i = 0; i < size; ++i)
			dArray[i] = obj.dArray[i];
	}
	return *this;
}

varArray::~varArray(){
	delete[] dArray;
}
