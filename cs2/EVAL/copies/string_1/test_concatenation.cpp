//

#include<iostream>
#include"string.hpp"

int main(){

  //string + char
  String one("abc");
  String two('d');
  String three = one + two;
  String four = one + two + three;
  std::cout << three;
}
