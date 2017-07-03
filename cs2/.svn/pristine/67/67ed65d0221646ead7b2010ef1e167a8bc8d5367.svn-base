//
//
//
//

#include <iostream>
#include "stack.hpp"
#include "string/string.hpp"
#include <cassert>

int main(){

  {
    // Default test with int type
    stack<int> one;
    one.push(1);
    assert(one.getTos() == 1);
  }

  {
    // Default test with String type
    stack<String> one;
    one.push("worked");
    assert(one.getTos() == "worked"); 
  }

  {
    // Copy ccnstructor test
    stack<int> one;
    one.push(1);
    stack<int>two(one); 
    assert(two.getTos() == 1);
  }

}
  
