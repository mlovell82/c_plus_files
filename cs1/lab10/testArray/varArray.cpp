// This file holds the functions used in the program
// Michael Lovell
// 13012
// 11/15/2015

#include <iostream>
#include "testarray.h"

using std::cout; using std::cin; using std::endl;

void output(int *arrayPtr, int size){
	for (int i = 0; i < size; i++)
		cout << *arrayPtr << endl;
}

int check(int *arrayPtr, int number, int size){
	for (int i = 0; i < size; i++){
		if (*arrayPtr == number)
			return i;
		else
			return -1;
	}
}

void addNumber(int *& arrayPtr, int number, int &size){

}
void removeNumber(int *& arrayPtr, int number, int &size){

}
