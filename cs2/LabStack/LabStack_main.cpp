#include <iostream>
#include "LabStack.hpp"

int main(){

  stack <int> one;
  stack <int> two;
  one.push(3);
  two.push(2);
  std::cout << one.getTos();
}
