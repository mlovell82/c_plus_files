/**
 * Michael Lovell
 * factorial.cpp
 * cs23001
 */
// This program uses the factorial() method to find 100! and it's trailing zeros

#include <iostream>
#include "bigint.hpp"

int main(){

  bigint ob1;
  int one_hundred = 100;

 ob1.factorial(one_hundred);

  std::cout << "Factorial method used while loop from 1 to 100 multiplying the loop variable each time to a bigint which started with the value of 1" << std::endl;
  std::cout << "A for loop in this program counted the zeros of an object whos value came from calling the factorial method on the int 100" << std::endl;

}
