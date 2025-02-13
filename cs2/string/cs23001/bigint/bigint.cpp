/**
 * Michael Lovell
 * bigint.cpp
 * cs23001
 */
// This program contains the function definitions for the bigint class

#include <iostream>
#include "bigint.hpp"
#include <cassert>

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
  int trailing_zeros_stopper = size;
  while (ob1.bigint_array[trailing_zeros_stopper] == 0) {
    --trailing_zeros_stopper;
  }
  ++trailing_zeros_stopper;
while (array_var < trailing_zeros_stopper)// This loop keeps function printing until end of array is reached
    {     
      for (int i = 0; i < 50; ++i){ // This loop prints 50 digits of the array out
	if (array_var < trailing_zeros_stopper){
	  out << ob1.bigint_array[array_var] << " ";
	  ++array_var;
	}
      }
      out << std::endl; // after 50 digits printed, this statment moves down one line
    }
  return out;
}

//Precondition:  accepts as an argument an istream and an object of "bigint"
//Postcondition:  reads txt file with the istream and places the digits into the bigint array
std::istream& operator>>(std::istream& file, bigint& rhs) {
  char digit_from_file;
  int i = 0;
  bigint temp;
  while (!file.eof()){
    file >> digit_from_file;
    if (file.eof())
      break;
    // If input is a digit, it is entered into a temp array
    if ((digit_from_file == '0') || (digit_from_file == '1') || (digit_from_file == '2') || (digit_from_file == '3') || (digit_from_file == '4') || (digit_from_file == '5') || (digit_from_file == '6') || (digit_from_file == '7') || (digit_from_file == '8') || (digit_from_file == '9')) {
      int char_as_int = (digit_from_file - '0');
      temp.bigint_array[i] = char_as_int;
      ++i;
    }
    // If the input is a ";" temp array is entered into the bigint array backwards so the digit is in the right place
    else
      if (digit_from_file == ';'){
	--i;
	for (int j =0; j < size; ++j){
	  rhs.bigint_array[j] = temp.bigint_array[i];
	  if (i == 0)
	    break;
	  --i;
	  }	   	  
	file >> digit_from_file;
	// After ";" we skip to the next numerical character as the loop enterst the next iteration
	if((digit_from_file == '0') || (digit_from_file == '1') || (digit_from_file == '2') || (digit_from_file == '3') || (digit_from_file == '4') || (digit_from_file == '5') || (digit_from_file == '6') || (digit_from_file == '7') || (digit_from_file == '8') || (digit_from_file == '9')){
	  file.putback(digit_from_file);
	  break;
	}
      }
  }
  return file;
}

// Precondition:  Two bigints
// Postcondition:  Output the sum of the bigints
bigint bigint::operator+(const bigint& right_side) {
  bigint result;
  int ten = 10;
  int carry_over = 0;
  for (int i = 0; i < size; ++i) {
    int element_sum = bigint_array[i] + right_side.bigint_array[i] + carry_over;
    if (element_sum < ten){
      result.bigint_array[i] = element_sum;
      carry_over = 0;
    }
    else
      {
	result.bigint_array[i] = (element_sum % ten);
	carry_over = element_sum / ten;
      }
  }
  return result;
}

// Precondition: i >= o and i < size
// Postcondition: return value is bigint_array[i]
int bigint::operator[](int number_to_search)const{
  assert(number_to_search >= 0);
  assert(number_to_search < size);
  return bigint_array[number_to_search];
}

//Precondition: 1 bigint and 1 int
//Postcondition: function multiplies the bigint by the int.  As each element is multiplied by the int
// the first branch hadles answers less than 10.  The second branch handles answers greater than 10
bigint bigint::times_digit(const int& b)const {
  bigint result;
  int carry_over = 0;
  int temp = 0;
  for(int i = 0; i < size; ++i){
    temp = bigint_array[i] * b;
    if (temp < 10){
      result.bigint_array[i] = temp + carry_over;
      carry_over = 0;
    }
    else {
      result.bigint_array[i] = (temp + carry_over) % 10;
      carry_over = (temp + carry_over) / 10;
    }
  }
  return result;
}
      
//Precondition: 1 bigints calling the function and 1 int passed by ref
//Postcondition:  This function will return a bigint shifted n times 10 with the int equal to n
bigint bigint::shift_right(const int &b)const {
  bigint result;
  for (int i = 0; i < size; ++i) {
    if (i < b) // any element before the int is equal to 0
      result.bigint_array[i] = 0;
    else if ((i >= b) && (i < (size - b))) // once we get to element n the value of the passed bigint is entered
      result.bigint_array[i] = bigint_array[i - b];
  }	     
return result;
}

//Precondition: 2 bigints
//Postcondition:  This function returns a bigint which is the product of the 2 bigints passed
bigint bigint::operator*(const bigint& rhs)const {
  bigint result;  
  int int_holder = 0;
  for (int i = 0; i < size; ++i) {
    // Value of iteration element of calling bigint is assigned to an int variable so it can be passed in the times_digit() method
    int_holder = bigint_array[i]; 
    bigint temp;
    temp = rhs.times_digit(int_holder);
    result = result + temp.shift_right(i);
  }
return result;
}
 
// Precondition: Integer passed by reference
// Postcondition: Function returns the factorial of the integer passed
void bigint::factorial(const int &hundred){
  bigint temp(1);
  int i = 1;
  while(i != (hundred + 1)){
    bigint j(i);
    temp = temp * j;
    ++i;
  }
  std::cout << temp << std::endl;
  // This for loop counts the trailing zeros
  for (int k = 0; k < size; ++k){
    if (temp.bigint_array[k] != 0){
      std::cout << k << " trailing zeros" << std::endl;
      k = size;
    }
  }  
}
