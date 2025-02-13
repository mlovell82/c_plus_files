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
  int loop = 1;
  //Until end of file
  while(!in.eof()) {
    bigint one;
    bigint two;
    std::cout << "Output for loop " << loop << std::endl;
    in >> one;
    in >> two;
    //Read two bigints
    std::cout << "Bigint 1: ";
    std::cout << one;
    std::cout << std::endl;
    std::cout << "Bigint 2: ";
    std::cout << two;
    std::cout << std::endl;
    //Print them out
    bigint three = one + two;
    //Add them together
    std::cout << "Bigint 3: ";
    std::cout << three;
    std::cout << std::endl;
    //Print out results
    ++loop;
  }
    in.close();
    return 0;
  }
