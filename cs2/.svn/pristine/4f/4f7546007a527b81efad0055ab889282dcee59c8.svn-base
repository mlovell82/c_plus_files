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
        bi = bi.shift_right(0); 


        // Verify
        assert(bi == 3);  //Wrong.  Add tests cases
    }

    {
    
    //shift_right function with a non zero integer argument.
      bigint bo(3);
      // Test
      bo = bo.shift_right(3);
 
      // Verify
      assert(bo == 3000);
    }
    {
     // Shift_right function with a 2 digit integer argument.
      bigint ba("123456789123456789123456789123456789");
      // Test
      ba = ba.shift_right(15);

      // Verify
      std::cout << ba << std::endl;
    }
    std::cout << "Done testing times10" << std::endl;
}

