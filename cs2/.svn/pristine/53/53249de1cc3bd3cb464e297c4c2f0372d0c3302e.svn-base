#include <iostream>
#include "profile.hpp"
profile shapeI_cpp("shapeI_cpp");
#include "profile.hpp"
profile shape_cpp("shape_cpp");
#include "shape.hpp"

int main(){shape_cpp.count(__LINE__, "main");
  shape a;
  a.move(3,4);shape_cpp.count(__LINE__);
  std::cout << shape_cpp << std::endl;
std::cout << shapeI_cpp << std::endl;
a.draw();shape_cpp.count(__LINE__);
}

