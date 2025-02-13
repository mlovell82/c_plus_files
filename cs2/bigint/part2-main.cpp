// Basics for openning a file for Part 2 of Project 1.
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
  std::ifstream in("data1-1.txt");    // Define stream for input
  if(!in) {                           // Make sure it opened correctly.
    std::cerr << "Could not open data1-1.txt, exiting." << std::endl;
    exit(1);
  }
  bigint one;
  bigint two;
  //Until end of file
  while(!in.eof()) {
    in >> one;
    in >> two;
    //Read two bigints
    std::cout << one;
    std::cout << two;
    //Print them out
    bigint three = one + two;
    //Add them together
    std::cout << three;
    //Print out results
    break;

    in.close();
    return 0;
  }


