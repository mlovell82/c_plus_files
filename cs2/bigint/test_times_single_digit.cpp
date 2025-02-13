// bigint Test Program
//
// Tests:  times_10, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.times_digit(1);  

        // Verify
        assert(bi == 3);  
    }
    {
      // Setup fixture
      bigint bo(123);

      // Test
      bo = bo.times_digit(2);

      // Verify
      assert(bo == 246);
    }
    {
      // Setup fixture
      bigint ba("123456789123456789123456789");

      // Test
      ba = ba.times_digit(2);

      // Verify
      std::cout << ba << std::endl;
    
    }
    std::cout << "Done testing bigint * single digit" << std::endl;

}
