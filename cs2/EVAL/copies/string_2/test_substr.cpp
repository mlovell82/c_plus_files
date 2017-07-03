
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
    String str2 = str.substr(2,4);
    assert(str2 == "cde");
    if(str2 == "cde")
      std::cout << "1 substring test passed" << std::endl;
  }
  {
    String str("hello");
    String str5 = str.substr(0,4);
    assert(str5 == "hello");
    if(str5 == "hello")
      std::cout << "7 substring test passed" << std::endl;

    //------------------------------------------------------

  }
}
