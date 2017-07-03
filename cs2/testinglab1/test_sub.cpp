#include "super_math.hpp"
#include <cassert>

int main(){

  int left = 5;
  int right = 4;
  int result;
 
  // Test
  result = left - right;

  // Verify
  assert(left == 5);
  assert(right == 4);
  assert(result == 1);
}
