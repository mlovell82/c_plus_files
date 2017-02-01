// car class member functions
// Mikhail Nesterenko
// 3/15/2016


#include <string>
#include <array>
#include <cstdlib>
#include "car.hpp"

Ford::Ford(){
  static const std::array<std::string, 4>
    models = {"Focus", "Mustang", "Explorer", "F-150"};
  make_ = "Ford";
  model_ = models[rand() % models.size()];
}

Toyota::Toyota(){
  static const std::array<std::string, 5>
    models = {"Corolla", "Camry",
              "Prius", "4Runner", "Yaris"};
  make_ = "Toyota";
  model_ = models[rand() % models.size()];
}

