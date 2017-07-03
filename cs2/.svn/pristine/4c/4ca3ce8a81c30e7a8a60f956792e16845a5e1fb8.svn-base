// bigint Test Program
//
// Tests:  int constructor, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
	bigint right(0);
	bigint result;

        //Test 
	result = left + right;

        // Verify
        assert(left   == 0);
	assert(right  == 0);
	assert(result == 0);
    }

	    

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(0);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 0);
      assert(result == 1);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 1);
      assert(result == 2);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(9);
      bigint right(9);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 9);
      assert(right  == 9);
      assert(result == 18);
    }

    
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("9");
      bigint right("9");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 9);
      assert(right  == 9);
      assert(result == 18);
    }

 
{
  //------------------------------------------------------
  // Setup fixture
  bigint left(9);
  bigint right("9");
  bigint result;

  // Test
  result = left + right;

  // Verify
  assert(left   == 9);
  assert(right  == 9);
  assert(result == 18);
}

 
{
  //------------------------------------------------------
  // Setup fixture
  bigint left("111111111111111111111111111111111111111111111");
  bigint right("222222222222222222222222222222222222222222222");
  bigint result;

  // Test
  result = left + right;
  std::cout << result;
  
}

 
    //Add test cases as needed.
    {
      // Setup fixture
      bigint left(100);
      bigint right(100);
      bigint result;    
      // Test
      result = left + right;
      // Verify
      assert(left == 100);
      assert(right == 100);
      assert(result == 200);
      }    
    std::cout << "Done with testing addition." << std::endl;
}

