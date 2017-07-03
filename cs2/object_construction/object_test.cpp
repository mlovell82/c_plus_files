// object_test.cpp

#include <iostream>
#include "object_construction.hpp"

int main(){

  dynamicArray one;

  dynamicArray two;

  two = one;

  one.copy(two);
}
