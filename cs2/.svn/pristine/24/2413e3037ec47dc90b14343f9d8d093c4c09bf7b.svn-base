
//  String class test program
//  Michael Lovell
//  Tests: member void functions
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
  {
    String str("abcdef");
    int element = str.findchar('c');
    assert(element == 2);
    if (element == 2)
      std::cout << "3 findchar test passed" << std::endl;
  }
  {
    //------------------------------------------------------
    // SETUP FIXTURE
    String  str("abcdef");

    // TEST
    int result = str.findchar('c');

    // VERIFY
    assert(result == 2);
    if(result == 2)
      std::cout << "9 findchar test passed" << std::endl;
  }
}
