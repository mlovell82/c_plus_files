
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
    String str("abc");
    char result = str[2];
    assert(str[2] == 'c');
    if(str[2] == 'c')
      std::cout << "1 subscript return test passed" << std::endl;
  }

  {
    String str("abc");
    str[2] = 'b';
    assert(str == "abb");
    if(str == "abb")
      std::cout << "2 subscript replace test passed" << std::endl;
  }

}
