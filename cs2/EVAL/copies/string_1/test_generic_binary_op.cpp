//  String class test program
//
//  Name:  XXX
//  Tests: XXX
//

#include "string.hpp"
#include <cassert>
#include <iostream>


int main() 
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abc");
        String  right("abc");

        // TEST
	char result;
	if(left == right)
        result = 'y';

        // VERIFY
	assert(result == 'y');
        assert(left   == "abc");
        assert(right  == "abc");
    }
    
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("abc");
        String  right("abcd");

        // TEST
	char result; 
	if (left < right)
	result = 'y';
        // VERIFY
        assert(result == 'y');
        assert(left   == "abc");
        assert(right  == "abcd");
    }
    
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      char  left[4] = {'a','b','c','\0'};
        String  right("abc");

        // TEST
	char result;
        if (left == right)
	  result = 'y';
        // VERIFY
        assert(result == 'y');
    }
    
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        char  left('a');
        String  right('a');

        // TEST
	char result;
        if (left == right)
          result = 'y';
        // VERIFY
        assert(result == 'y');

    }
    
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        char  left('a');
        String  right("abc");

        // TEST
         char result;
	 if (left < right)
          result = 'y';
        // VERIFY
        assert(result == 'y');

    }
    
    {
        //------------------------------------------------------
        // SETUP FIXTURE
      char  left[4] = {'a','b','c','\0'};
        String  right("abcdef");

        // TEST
	char result;
	if (left < right)
          result = 'y';
        // VERIFY
        assert(result == 'y');

    }
    {
      //------------------------------------------------------
      // SETUP FIXTURE
      String  left("abc");
      String  right("abcdef");
      String zero;
      // TEST
      char result;
      if (left <= right)
	result = 'y';
      char result2;
      if (zero <= right)
	result2 = 'Y';
      // VERIFY
      assert(result == 'y');
      assert(result2 == 'Y');

    }
    {
      //------------------------------------------------------
      // SETUP FIXTURE
      String  left("ghi");
      String  right("abcdef");

      // TEST
      char result;
      if (left != right)
	result = 'y';
      // VERIFY
      assert(result == 'y');

    }
    //------------------------------------------------------
    {
    // SETUP FIXTURE
    String  left("abcde");
    String  right("abcd");
    String middle("abcde");

    // TEST
    char result, result2;
    if (left >= right)
      result = 'y';
    if (middle >= right)
      result2 = 'Y';
    // VERIFY
    assert(result == 'y');
    assert(result2 == 'Y');
    }
    {
    // ADD ADDITIONAL TESTS AS NECESSARY
    // SETUP FIXTURE
    String  left("abcde");
    String  right("abcd");
    
    // TEST
    char result, result2;
    if (left > right)
      result = 'y';
    
    // VERIFY
    assert(result == 'y');
    
    }
    std::cout << "Done testing XXX." << std::endl;
}
