#include <iostream>
#include "shape.hpp"

void shape::draw(){
  std::cout << "A shape" << "at" << x << y << std::endl;
}

void shape::move(int a, int b){
  x = a; y = b;
}
