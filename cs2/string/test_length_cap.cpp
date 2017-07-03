
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
    //------------------------------------------------------
    // SETUP FIXTURE
    String  str("abcde");

    // TEST
    int result = str.length();

    // VERIFY

    assert(result == 5);
    if(result == 5)
      std::cout << "5 length test passed" << std::endl;
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    String  str("abcde");

    // TEST
    int result = str.capacity();
    
    // VERIFY
        assert(result == 1);
    if(result == 1)
      std::cout << "6 capacity test passed" << std::endl;
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE

    String  str('a');
    char b = 'b';
    for (int i = 0; i < 3; ++i)
      str = str + b;
    // TEST
    int result = str.length();

    // VERIFY
    assert(result == 4);
    std::cout << "10 length() test passed" << std::endl;
  }

  {
    String str("abcd");
    int cap = str.capacity();
    std::cout << cap << std::endl;
    str.resetCapacity(3);
    cap = str.capacity();
    std::cout << cap << std::endl;
    std::cout << str << std::endl;
  }

  // ADD ADDITIONAL TESTS AS NECESSARY

  std::cout << "Done testing XXX." << std::endl;
}
