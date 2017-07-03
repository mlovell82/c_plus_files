#include<iostream>
#include"string.hpp"
#include<cassert>

int main(){

  String one("abc");
  String two("abc");
  String three("def");
  
  if(one == two)
    std::cout << "case 1 is equal" << std::endl;
  //  if(two == three)
  //  std::cout << "case 2 is equal" << std::endl;
}
