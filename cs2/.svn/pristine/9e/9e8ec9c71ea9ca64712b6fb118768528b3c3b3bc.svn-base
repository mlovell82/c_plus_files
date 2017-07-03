
// Michael Lovell
// Tests binary operators
// cs23001

#include "string.hpp"
#include <cassert>
#include <iostream>

int main(){
  {
    String one("abc");
    String two("abc");
    assert (one == "abc");
    assert (two == "abc");
    if(one == two)
      std::cout << "1 passed" << std::endl;
  }
  {

    String one("abc");
    String three("abcdef");
    assert (one < three);
    if(one < three)
      std::cout << "2 passed" << std::endl;
  }
  {

    String one("abc");
    char four[4] = {'a','b','c','\0'};
    assert (one == four);
    if(four == one)
      std::cout << "3 passed" << std::endl;
  }
  {

    String five('a');
    char char_one = 'a';
    assert (char_one == five);
    if(char_one == five)
      std::cout << "4 passed" << std::endl;
  }
  {

    String three("abcdef");
    char four[4] = {'a','b','c','\0'};
    assert (four < three);
    if(four < three)
      std::cout << "5 passed" << std::endl;
  }
  {
    String one("abc");
    char char_one = 'a';
    assert(char_one < one);
    if(char_one < one)
      std::cout << "6 passed" << std::endl;
  }
  {

    String one("abc");
    String two("abc");
    assert (one <= two);
    if(one <= two)
      std::cout << "7 passed" << std::endl;

  }
  {

    String one("abc");
    String three("abcdef");
    assert(one <= three);
    if(one <= three)
      std::cout << "8 passed" << std::endl;
  }
  {

    String one("abc");
    String three("abcdef");
    assert(one != three);
    if(one != three)
      std::cout << "9 passed" << std::endl;
  }
  {

    String one("abc");
    String three("abcdef");
    assert(three >= one);
    if(three >= one)
      std::cout << "10 passed" << std::endl;
  }
  {

    String one("abc");
    String two("abc");
    assert (two >= one);
    if(two >= one)
      std::cout << "11 passed" << std::endl;
  }
  {

    String one("abc");
    String three("abcdef");
    assert(three > one);
    if(three > one)
      std::cout << "12 passed" << std::endl;
  }
  std::cout << "Done testing XXX." << std::endl;

  {
    String str("abc");
    char result = str[2];
    assert(result == 'c');
    if(result == 'c')
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
