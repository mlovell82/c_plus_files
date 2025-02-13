//  String class test program
//
//  Tests: XXX
//

#include "string.hpp"
#include <cassert>
#include <iostream>
#include <fstream>

//===========================================================================
int main ()
{

  {
    String str("abcd");
    int cap = str.capacity();
    std::cout << cap << std::endl;
    str.resetCapacity(3);
    cap = str.capacity();
    std::cout << cap << std::endl;
    std::cout << str << std::endl;    
  }
  
  {
      std::ifstream in("log_1_tiny.txt");    // Define stream for input
      if(!in) {                           // Make sure it opened correctly.
	std::cerr << "Could not open data1-1.txt, exiting." << std::endl;
	//exit(1);
      }
      int loop = 1;
      //Until end of file
      while(!in.eof()) {
	String one;
	in >> one;
	//Read in
	std::cout << "String" << loop << ":" << " " << std::endl;
	std::cout << one << std::endl;
	//Print out results
	++loop;
      }
      in.close();
      

    }
  
    {
        //------------------------------------------------------
        // SETUP FIXTUR*
      String str("abc");
      String str2("def");
      String str3 = str + str2;
      if(str3 == "abcdef")
	std::cout << "String to String concat test passed" << std::endl;

        // VERIFY
      assert(str3 == "abcdef");
    }
  
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abc");
	char d = 'd';
        // TEST
        String str2 = d + str;
	
	if(str2 == "dabc")
	  std::cout << "char to string concat test passed" << std::endl;
        // VERIFY
	assert(str2 == "dabc");
    }
    
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abc");
	char more[4] = {'d','e','f','\0'};
        // TEST
        String str2 = more + str;
	
	if(str2 == "defabc")
	  std::cout << "char array to String concat test passed" << std::endl;
        // VERIFY
	 assert(str2 == "defabc");
    }
    
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str;
	String str2;
        // TEST
	String str3 = str + str2;

        // VERIFY
        assert(str3[0] == 0);
	std::cout << "default + default passed" << std::endl;
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str;
	String str2("abc");
        // TEST
        String str3 = str + str2;

        // VERIFY
        assert(str3 == "abc");
	std::cout << "default + string passed" << std::endl;
    }
    

    // ADD ADDITIONAL TESTS AS NECESSARY
    std::cout << "Done testing XXX." << std::endl;

}

