
//  String class test program
//
//  Tests: XXX
//

#include "string.hpp"
#include <cassert>
#include <iostream>
#include <fstream>

//===========================================================================
int main ()
{
  {
    std::ifstream in("log_1_tiny.txt");    // Define stream for input
    if(!in) {                           // Make sure it opened correctly.
      std::cerr << "Could not open data1-1.txt, exiting." << std::endl;
      //exit(1);
    }
    int loop = 1;
    //Until end of file
    while(!in.eof()) {
      String one;
      in >> one;
      //Read in
      std::cout << "String" << loop << ":" << " " << std::endl;
      std::cout << one << std::endl;
      //Print out results
      ++loop;
    }
    in.close();


  }
}
