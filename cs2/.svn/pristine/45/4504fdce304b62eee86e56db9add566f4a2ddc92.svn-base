
// File string.cpp
// Michael Lovell
// cs23001


#include <iostream>
#include "string.hpp"
#include <cassert>
//===========================================================================
int main ()
{

  {
    //------------------------------------------------------
    // SETUP FIXTURE

    // TEST
    String  str;

    // VERIFY
    std::cout << str;
  }


  {
    //------------------------------------------------------
    // SETUP FIXTURE

    // TEST

    String str2('a');


    // VERIFY
    if(str2 == 'a')
      std::cout << "1 char constructor test passed" << std::endl;
    assert(str2 == 'a');
  }


  {
    //------------------------------------------------------
    // SETUP FIXTURE

    // TEST
    String  str("xyz");

    // VERIFY
    assert(str == "xyz");
    if (str == "xyz")
      std::cout << "2 char string constructor test passed" << std::endl;
  }


  {
    //------------------------------------------------------
    // SETUP FIXTURE

    // TEST
    String  str("abcdefghijklmnopqrstuvwxyz");

    // VERIFY
    assert(str == "abcdefghijklmnopqrstuvwxyz");
    if(str == "abcdefghijklmnopqrstuvwxyz")
      std::cout << "3 long string constructor test passed" << std::endl;
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE

    // TEST
    String  str(5,"abcd");

    // VERIFY
    assert(str == "abcd");

    if(str == "abcd")
      std::cout << "4 int, char string constructor test passed" << std::endl;
  }

  {
    // TEST
    String str(5);
    //std::cout << str << std::endl;
  }

  {
    //TEST
    String str("abc");
    String str2(str);
    if(str2 == "abc")
      std::cout << "5 copy constructor test passed" << std::endl;
    assert (str2 == "abc");
  }

  {
    String str("abc");
    //    str.~String();
    // Default test (i stuck a cout in the method definition and although it prints alot of jibberish it did print my statement and pass the test
  }
  {
    String str("abc");
    String str2("abc");
    String str3("def");
    str = str2;
    assert (str == "abc");
    if(str == "abc")
      std::cout << "6 assignment operator with same valued Strings test passed" << std::endl;
    str = str3;
    assert (str == "def");
    if(str == "def")
      std::cout << "7 assignment operator with different valued Strings test passed" << std::endl;
  }
  {
    String str("abc");
    String str2("def");
    str.swap(str2);
    assert (str2 == "abc");
    assert (str == "def");
    if((str == "def") && (str2 == "abc"))
      std::cout << "8 swap test passed" << std::endl;
  }
  // ADD ADDITIONAL TESTS AS NECESSARY
  std::cout << "Done testing XXX." << std::endl;

}
