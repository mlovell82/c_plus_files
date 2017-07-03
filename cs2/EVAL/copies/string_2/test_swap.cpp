
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
    String str("abc");
    String str2("cde");
    str.swap(str2);
    assert(str == "cde");
    assert(str2 == "abc");
  }

  {
    String str('a');
    String str2("bcde");
    str.swap(str2);
    assert(str == "bcde");
    assert(str2 == 'a');
  }
}
