// File string.cpp
// Michael Lovell
// cs23001


#include <iostream>
#include "string.hpp"
#include <cassert>
#include <vector>

// Default Constructor
// Requires:  no preconditions 
// Ensures:  creates an empty String object
String::String(){
  Capacity = DEFAULT_STRING_CAPACITY;
  s = new char[Capacity];
  s[0] = 0;
}

// Char Constructor
// Requires:  1 character
// Ensures:  creates a String object composed of the character passed
String::String(char ch){
  Capacity = DEFAULT_STRING_CAPACITY;  
  s = new char[Capacity];
  s[0] = ch;
  s[1] = 0;
}

// Char array constructor
// Requires: an array of characters
// Ensures:  constructs them into a String object
String::String(const char* ch){
  char* temp = (char*)ch;//new char[Capacity];
  int i = 0;
  while(temp[i] != 0){
    ++i;
  }
  Capacity = (i + 1);
  s = new char[Capacity];  
  int j = 0; // While loop variable
  while (ch[j] != 0){
    s[j] = ch[j];
    ++j;
    if(j == Capacity)
      break;
  }
  s[j] = 0;
}

// Constructor with int and char arguments
// Requires: n >=0 and a character
// Ensures: Capacity of the array is n and the first element is ch
String::String(int n, const char* ch){
  Capacity = n;
  s = new char[n];
  int i = 0;
  while (ch[i] != 0){
    s[i] = ch[i];
    ++i;
    if (i >= (n - 1)) break;
  }
  s[i] = 0;
}

// Constructor with an int argument
// Requires: n >= 0;
// Ensures: Capacity of array is = n
String::String(int n){
  Capacity = n;
  s = new char[n];
}
 
// Copy constructor
// Requires: A String object by reference
// Ensures: When a String is passed by value this method creates a copy with its own dynamic array
String::String(const String &copiedString){
  Capacity = copiedString.Capacity;
  s = new char[Capacity];
  for(int i = 0; i < Capacity; ++i)
    s[i] = copiedString.s[i];
}

// Destructor
// Requires: A String object going out of scope
// Ensures:  Memory reallocated to the heap to prevent memory leak
String::~String(){
  delete [] s;
}

// Assignment operator
// Requires: A String object by value
// Ensures: Copies passed String value to the calling String without accidently deleting the pointer if they are already equal
String& String::operator=(String copiedString){
  swap(copiedString); 
  return *this;
}

// + Operator Overload
// Requires: 2 strings with a sum of 256 characters or less
// Ensures: combines strings together in one string
String String::operator+(const String& addOn)const{
  String result;
  //  for(int i = 0; i < Capacity; ++i)
  int i = 0;
  while (s[i] != 0){
    result.s[i] = s[i];
    ++i;
  }
  int j = 0;
  while(addOn.s[j] != 0){
    result.s[i] = addOn.s[j];
    ++j;
    ++i;
  }
  result.s[i] = 0;
  return result;
}

// Swap method
// Requires:  A String object passed and a String object calling
// Ensures: Switches dynamic arrays between 2 objects
void String::swap(String &swapee){ 
  char *temp = s;
  s = swapee.s;
  swapee.s = temp;
  int tempn = Capacity;
  Capacity = swapee.Capacity;
  swapee.Capacity = tempn;
}

// ResetCapacity method
// Requires:  0 =< n =< Capacity 
void String::resetCapacity (int n){
  char *temp = new char[n];
  int smaller = Capacity;
  if(n < Capacity)
    smaller = n;
  for(int i = 0; i < smaller; ++i)
    temp[i] = s[i];
  delete []s;
  s = temp;
  Capacity = n;
}

// Subscript Operator
// Requires:  an int greater than or equal to zero, and less than DEFAULT_STRING_CAPACITY
// Ensures:  returns char at the element number of the int passed by the method
char& String::operator[](int elementFinder){
  assert (elementFinder >= 0);
  assert (elementFinder < Capacity);
  return s[elementFinder];
}

// Subscript Operator
// Requires:  1 String object and an int from 0 to DEFAULT_STRING_CAPACITY
// Ensures:  finds the character at the element number matching the int passed
char String:: operator[](int elementFinder) const{
  assert (elementFinder >= 0);
  assert (elementFinder < Capacity);
  return s[elementFinder];

}

// == Operator overload
// Requires: 2 String objects
// Ensures:  Returns true if they are equal
bool String::operator==(const String &rhs) const{
  int i = 0;
  while((s[i] != 0) && (s[i] == rhs.s[i]))
    ++i;
  return (s[i] == rhs.s[i]);
}

// < Operator overload
// Requires:  2 string objects
// Ensures:  Returns true if object on left is less than object on the right
bool String::operator<(const String&rhs) const{
  
  int i = 0;
  while((s[i] != 0) && (rhs.s[i] != 0) && (s[i] == rhs.s[i]))
    ++i;    
  return (s[i] < rhs.s[i]);
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
  const char *temp = character;  
  return String(temp) < stringArray;
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
  int temp = object.length(); //trying  
  for (int i = 0; i < temp; ++i)//object.Capacity  
    out << object.s[i];
  return out;
}

// >>Operator overload
// Requires:  a String object and an input stream
// Ensures:  loads data from input stream into a String object
std::istream& operator>>(std::istream& in, String& object){
  int tempCap = object.capacity();
  char temp[tempCap];
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
  assert (finish < Capacity);
  String temp;
  int k = 0;
  int j = start;
  for (int i = 0; i <= (finish - start); ++i){
    temp.s[i] = s[j];
    ++j;
    ++k;
  }
  temp.s[k] = 0;
  return temp;
}

// findstr() method
// Requires:  called by a String object and passes a char array and int for length
// Ensures:  Returns an int
int String::findstr(int length, const char *charArray)const{
  int j = 0;
  int i =0;  
  int found = 0;
  while (found != length){
    if(s[j] == charArray[i]){
      for(int k = 0; k < length; ++k){
	if(s[j] == charArray[k]){
	  ++found;
	  ++j;
	}
	else{
	  found = 1;
	  ++j;
	  break;
	}
      }
    }
    else
      ++j;
  }
  found = j - found;
  return found;
} 
// findchar() method
// Requires:  called by a String and passes a char
// Ensures:  if char is in string the element location is returned
int String::findchar(char character)const{
  for(int i = 0; i < Capacity; ++i)
    if (s[i] == character)
      return i;
  return -1;
}

// length() method
// Requires:  called by a String object with no arguments
// Ensures:  Returns size of the String object
int String::length()const{
  int length = 0;
  while (s[length] != 0)
    ++length;
  return length;
}
 
// Capacity() method
// Requires: called by a String object with no arguments
// Ensures:  Returns remaining capacity not filled by characters
int String::capacity() const{
  int length = 0;
  while (s[length] != 0)
    ++length;
  return (Capacity - length);
}

// Split()
// Requires: called by a String object and has a char as an argument
// Ensures that substrings between the char passed are seperated into a vector of String objects
std::vector<String> String::split(char skipper) const{
  std::vector<String> result;
  int length = 0;
  while (s[length] != 0)
    ++length;

  for(int i = 0; i < length; ++i){
    String temp;
    int j = 0;
    while((s[i] != skipper) && (s[i] != 0))
      {
	temp.s[j] = s[i];
	++i;
	++j;
      }
    if(temp.s[0] != 0){
      temp.s[j] = 0;
         
      result.push_back(temp);
    }
  }
  return result;
}
