/**
 * Michael Lovell
 * bigint.cpp
 * cs23001
 */
// This program contains the function definitions for the bigint class

#include <iostream>
#include "bigint.hpp"

// Default constructor placing zeros in each array element
bigint::bigint(){
  for (int i = 0; i < size; ++i)
    bigint_array[i] = 0;
}

// This method fills the ones place digit of an int into the array with each itteration of a loop
// Then moves all the other digits one place so the tens place is in the ones place
bigint::bigint(int number_entered) {
  for (int i = 0; i < size; ++i)
    bigint_array[i] = 0;

  int array_var = 0; // loop var to assign 0th element with ones place digit
  int ten = 10; // variable used to move from ones place to tens to hundreds ect.
  int final_digit = -1; // while loop proceeds till this value changes with the last digit
    while (final_digit < 0){
      if (number_entered < ten){
	final_digit = number_entered;
	bigint_array[array_var] = number_entered;
      }
      else // number_entered is more than 2 digits
	{
	  bigint_array[array_var] = (number_entered % ten); // peel off the ones place digit and fill into bigint array
	  number_entered = (number_entered / ten); // move tens place to the ones place
	  ++array_var; // decrement to assign next element
	}
    }
}

// This method loops thru the char array till it reaches the sentinle value
// Then it goes backwards filling the numeric value of each char into the bigint array
bigint::bigint(const char char_array[]) {
  for (int i = 0; i < size; ++i) // filling each bigint element with zeros
    bigint_array[i] = 0;

  int array_var  = 0; // This will be the index variable for the bigint array
  for (int j = 0; j < size; ++j){ // iterating thru array to find sentinel value
    if (!((char_array[j] == '0') || (char_array[j] == '1') || (char_array[j] == '2') || (char_array[j] == '3') || (char_array[j] == '4') || (char_array[j] == '5') || (char_array[j] == '6') || (char_array[j] == '7') || (char_array[j] == '8') || (char_array[j] == '9'))){
      int k = j; // k will be used as the loop variable as we reverse char array, filling values into bigint array
	while (k > 0)
	  {
	    bigint_array[array_var] = (char_array[k - 1] - '0');
	    --k; 
	    ++array_var;
	  }
	j = size; // once filling is complete j is assigned the value of size to end the for loop
      }
  }
}

// comparison overload if the object calling does not equal the object passed 
// bool value of false is returned, otherwise true is returned
bool bigint::operator==(const bigint& right_bigint)const{
  for (int i = 0; i < size; ++i)
    if (!(bigint_array[i] == right_bigint.bigint_array[i]))
      return  false;
  return true;
}

// output function prints while array is less than size
// but only 50 digits per line
std::ostream& operator<<(std::ostream& out, const bigint ob1){
  int array_var = 0; // index variable to select array element
  while (array_var < size)// This loop keeps function printing until end of array is reached
    {
      for (int i = 0; i < 50; ++i){ // This loop prints 50 digits of the array out
	if (array_var < size){
	  out << ob1.bigint_array[array_var] << " ";
	  ++array_var;
	}
      }
      out << std::endl; // after 50 digits printed, this statment moves down one line
    }
  return out;
  

}
