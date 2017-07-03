#include <iostream>
#include "profile.hpp"
extern profile shapeI_cpp;
#include "shape.hpp"

void shape::draw(){shapeI_cpp.count(__LINE__, "shape::draw");
  std::cout << "A shape" << "at" << x << y << std::endl;shapeI_cpp.count(__LINE__);
}

void shape::move(int a, int b){shapeI_cpp.count(__LINE__, "shape::move");
  x = a;shapeI_cpp.count(__LINE__); y = b;shapeI_cpp.count(__LINE__);
}

