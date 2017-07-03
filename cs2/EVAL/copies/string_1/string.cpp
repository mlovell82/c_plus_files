


// File string.cpp
// Michael Lovell
// cs23001


#include <iostream>
#include "string.hpp"
#include <cassert>

// Default Constructor
// Requires:  no preconditions 
// Ensures:  creates an empty String object
String::String(){
  str[0] = 0;
}

// Char Constructor
// Requires:  1 character
// Ensures:  creates a String object composed of the character passed
String::String(char ch){
  str[0] = ch;
  str[1] = 0;
}

// Char Array Constructor
// Requires:  an array of characters no larger than DEFAULT_STRING_CAPACITY
// Ensures:  creates a String object composed of characters from the char array
String::String(const char ch[]){
  int i = 0; // While loop variable
  while (ch[i] != 0){
    str[i] = ch[i];
    ++i;
    if (i >= DEFAULT_STRING_CAPACITY) break;
  }
  str[i] = 0;
}

// + Operator Overload
// Requires: 2 strings with a sum of 256 characters or less
// Ensures: combines strings together in one string
String String::operator+(const String& addOn)const{
  String result;
  for(int i = 0; i < DEFAULT_STRING_CAPACITY; ++i)
    result.str[i] = str[i];
  int i = 0;
  int j = 0;
  while(addOn.str[i] != 0){
    if (str[j] != 0)
      ++j;
    else
      {
	result.str[j] = addOn.str[i];
	++j;
	++i;
      }
  }
return result;
}

// Subscript Operator
// Requires:  an int greater than or equal to zero, and less than DEFAULT_STRING_CAPACITY
// Ensures:  returns char at the element number of the int passed by the method
char& String::operator[](int elementFinder){
  assert (elementFinder >= 0);
  assert (elementFinder < DEFAULT_STRING_CAPACITY);
 return str[elementFinder];
}

// Subscript Operator
// Requires:  1 String object and an int from 0 to DEFAULT_STRING_CAPACITY
// Ensures:  finds the character at the element number matching the int passed
char String:: operator[](int elementFinder) const{
  assert (elementFinder >= 0);
  assert (elementFinder < DEFAULT_STRING_CAPACITY);
  return str[elementFinder];

}

// == Operator overload
// Requires: 2 String objects
// Ensures:  Returns true if they are equal
bool String::operator==(const String &rhs) const{
  int i = 0;
  while((str[i] != 0) && (str[i] == rhs.str[i]))
    ++i;
  return (str[i] == rhs.str[i]);
}

// < Operator overload
// Requires:  2 string objects
// Ensures:  Returns true if object on left is less than object on the right
bool String::operator<(const String&rhs) const{
  
  int i = 0;
  while((str[i] != 0) && (rhs.str[i] != 0) && (str[i] == rhs.str[i]))
    ++i;    
  return (str[i] < rhs.str[i]);
  }

// +Operator overload
// Requires:  1 array of characters and one String object
// Ensures:  concatonates the two into on String object    
String operator+(const char charArray[],  const String& stringArray){
  return String(charArray) + stringArray;
}

// +Operator overload
// Requires:  1 array of characters and one String object
// Ensures:  concatonates the two into on String object
String operator+(char character, const String& stringArray){
  return String(character) + stringArray;
}

// ==Operator overload
// Requires:  1 array of characters and one String object
// Ensures:  Returns true if they are both equal
bool operator==(const char character[], const String& stringArray){
  return String(character) == stringArray;
}

// ==Operator overload
// Requires:  1 array of characters and one String object
// Ensures:  Returns true if they are both equal
bool operator==(char character, const String& stringArray){
  return String(character) == stringArray;
}

// <Operator overload
// Requires:  1 array of characters and one String object
// Ensures:  Returns true if the character array is greater than the String
bool operator<(const char character[],  const String& stringArray){
  return String(character) < stringArray;
}

// <Operator overload
// Requires:  1 array of characters and one String object
// Ensures:  Returns true if the character array is greater than the String
bool operator<(char character, const String& stringArray){
  return String(character) < stringArray;
}

// <=Operator overload
// Requires:  2 String objects
// Ensures:  Returns true if the left operand is not greater than the right operand
bool operator<=(const String& stringOne, const String&stringTwo){
  return  !(stringOne > stringTwo);
}

// !=Operator overload
// Requires:  2 String objects
// Ensures:  Returns true if they are not equal
bool operator!=(const String& stringOne, const String& stringTwo){
  return !(stringOne == stringTwo);
}

// >=Operator overload
// Requires:  2 String objects
// Ensures:  Returns true if the left operand is less than the right operand
bool operator>=(const String& stringOne, const String& stringTwo){
  return !(stringOne < stringTwo);
}

// >Operator overload
// Requires:  2 String objects
// Ensures:  Returns true if the left operand is greater than the right operand
bool operator>(const String& stringOne, const String& stringTwo){
  return stringTwo < stringOne;
}

// <<Operator overload
// Requires:  a String object and an output stream
// Ensures:  outputs each value of that object to the stream destination
std::ostream &operator<<(std::ostream &out, const String &object){
  out << object.str;
  return out;
}

// >>Operator overload
// Requires:  a String object and an input stream
// Ensures:  loads data from input stream into a String object
std::istream& operator>>(std::istream& in, String& object){
  char temp[DEFAULT_STRING_CAPACITY];
  in >> temp;
  object = String(temp);
  return in;
}  

// substr() method
// Requires:  called on a String object and passes 2 ints from 0 to DEFAULT_STRING_CAPACITY
// Ensures:  Returns substring of the String calling from element of the first int to element of 2nd int
String String::substr(int start, int finish)const{
  assert (0 <= start);
  assert (start <= finish);
  assert (finish < DEFAULT_STRING_CAPACITY);
String temp;
  int j = 0;
  for (int i = 0; i < DEFAULT_STRING_CAPACITY; ++i)
    if ((i >= start) && (i <= finish)){
      temp.str[j] = str[i];
      ++j;
    }
  return temp;
}

// findstr() method
// Requires:  called by a String object and passes a char array and int for length
// Ensures:  Returns an int
int String::findstr(int length, const char charArray[])const{
  int j,i,k;
  for (j = 0; str[j]!= 0;++j){
      i = 0;
      if(str[j] == charArray[i]){
	while(str[j] == charArray[i]){
	  ++i; 
	  ++j;
	}
	if (charArray[i] == 0){
	  k = j - length;
	  return k;
      }
      
    }
  }
  return 0;
}
  
// findchar() method
// Requires:  called by a String and passes a char
// Ensures:  if char is in string the element location is returned
int String::findchar(char character)const{
  for(int i = 0; i < DEFAULT_STRING_CAPACITY; ++i)
    if (str[i] == character)
      return i;
  return -1;
}

// length() method
// Requires:  called by a String object with no arguments
// Ensures:  Returns size of the String object
int String::length()const{
  int length = 0;
  while (str[length] != 0)
    ++length;
  return length;
}
	 

int String::capacity() const{
  int length = 0;
  while (str[length] != 0)
    ++length;
  return (DEFAULT_STRING_CAPACITY - length);
}
