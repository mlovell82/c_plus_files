// object_construction.hpp
#include <iostream>

#ifndef OBJECT_CONSTRUCTION_HPP
#define OBJECT_CONSTRUCTION_HPP
class dynamicArray{
public:
  dynamicArray();
  dynamicArray(const dynamicArray&);
  ~dynamicArray();
  dynamicArray& operator=(const dynamicArray&);
  void copy(dynamicArray); //this function was created to call copyconstructor
private:
  int *ptr;
};
#endif
