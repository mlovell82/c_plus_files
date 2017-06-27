// Functions for the program
// Michael Lovell
// 11/27/2015
// 

# include "varArray.h"

varArray::varArray(){

}
int arraySize() const { return size; } // returns the size of the array

int check(int number); // returns index of element containg "number" or -1 if none
void addNumber(int);    // adds number to the array
void removeNumber(int); // deletes the number from the array
void output();      // prints the values of the array

// big three
varArray(const varArray&); // copy constructor
varArray& operator=(const varArray&); // overloaded assignment
~varArray(); // destructor
