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
    int element = str.findstr(3, "cde");
    assert(element == 2);
    if(element == 2)
      std::cout << "2 findstring test passed" << std::endl;
  }
  {
    //------------------------------------------------------
    // SETUP FIXTURE
    String  str("abcdef");
    // TEST
    int result = str.findstr(2,"cd");
    // VERIFY
    if (result == 2)
      std::cout << "8 findstr test passed" << std::endl;
    assert(result == 2);
  }
}
