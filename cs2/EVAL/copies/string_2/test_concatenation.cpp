//
#include<cassert>
#include<iostream>
#include"string.hpp"

int main(){
  {

  //string + char
  String one("abc");
  String two('d');
  String three = one + two;
  String four = one + two + three;
  std::cout << three;
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
