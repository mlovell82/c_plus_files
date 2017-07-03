// File:        logentry.cpp  
//       
// Version:     1.0
// Date: 3/27/2016        
// Author:  Michael Lovell      
// cs23001
// Description: Class implementation for a log entry.
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <fstream>
#include "string.hpp" 
#include "logentry.hpp"

////////////////////////////////////////////////////////// 
// LogEntry constructor
// ENSURES: REQUIRES: A String object
//ENSURES: Outputs a vector of elements of the String seperated by a space
LogEntry::LogEntry(String s) {
    // ...
  
    std::vector<String> vec = s.split(' ');
    host = vec[0];
    String temp = vec[3];
    String yearString = temp.substr(4,12);
    String yearString2;
    for(int i = 0; i < (yearString.length() + 1); ++i){
      if(yearString[i] == '/')
	for(int j = 0; j < 4; ++j){
	  ++i;
	  yearString2[j] = yearString[i];
	  if(j == 3)
	    yearString2[j + 1] = 0;
	     }
	}
    int yearNumb = 0;
    int tens = 1000;
    for(int i = 0; i < 4; ++i){
      yearNumb = yearNumb + ((yearString2[i] - '0') * tens);
      tens = tens / 10;
    }
    String tempMonth(5);
    String tempMonthWithDash = temp.substr(4, 7);
    int j = 0;
    for (int i = 0; i < (tempMonthWithDash.length() + 1); ++i)
      if (tempMonthWithDash[i] != '/'){
	tempMonth[j] = tempMonthWithDash[i];
	++j;
      }
    date.setDate(temp.substr(1,2), tempMonth, yearNumb);    
    int tempHour = 0;
    int tempMinute = 0;
    int tempSecond = 0;
    String timeTemp = temp.substr(13,20);    
    tempHour = (timeTemp[1] - '0') + ((timeTemp[0] - '0') * 10);
    tempMinute = (timeTemp[4] - '0') + ((timeTemp[3] - '0') * 10);
    tempSecond = (timeTemp[7] - '0') + ((timeTemp[6] - '0') * 10);
    time.setTime(tempHour,tempMinute,tempSecond);
    request = (vec[5] + vec[6] + vec[7]);
    status = vec[8];
    int byte = 0;
    String byteString = vec[9];
    bool possitive = true;
    int byteTens = 1;
    String minus("-");
    for(int i = (byteString.length() - 1); i >= 0; --i){
      if(byteString[i] != minus){
	byte = byte + ((byteString[i] - '0') * byteTens);
	byteTens = byteTens * 10;
      }
      if(byteString[i] == minus)
	possitive = false;
    }
    number_of_bytes = byte;
    if(!possitive)
      number_of_bytes = number_of_bytes * -1;
}

    // setDate method
    // Requires:  2 Strings and an int
    // Ensures:  that the Strings and int passed are saved as Date's day, month, and year
    void Date::setDate(String paramDay, String paramMonth, int paramYear){
  day = paramDay;
  month = paramMonth;
  year = paramYear;
}

    // setTime method
    // Requires:  3 ints(the first 2 are 2 digits and 1 is 4 digits)
    // Ensures:  that the ints passed are saved as Time's hour, minute, and second
 void Time::setTime(int paramHour, int paramMinute, int paramSecond){
  hour = paramHour;
  minute = paramMinute;
  second = paramSecond;
}

////////////////////////////////////////////////////////// 
// parse method
// REQUIRES:  File and an input stream
//ENSURES: Creates a logentry object for each line
std::vector<LogEntry> parse(std::istream& in) {
  std::vector<LogEntry> result;
 char a;
 String one;
 String two;
 while (!in.eof()){  
   in.get(a);    
   if(a != '\n')
     one = one + a;
   if(a == '\n'){
     if (one != two){   
       LogEntry tom(one);
       result.push_back(tom);
       one = two;
     }
   }
 }
return result;   
}

// Output operator overload
// Requires:  a stream and a LogEntry object
// Ensures:  the members of the object are outputed to the stream
std::ostream& operator<<(std::ostream &out, const LogEntry &tom){
  out << tom.host << " ";
  String tempDay = tom.date.getDay();
   out << tempDay << "/";
   String tempMonth = tom.date.getMonth();
   out << tempMonth << "/";
   int tempYear = tom.date.getYear();
   out << tempYear << " ";
   int tempHour = tom.time.getHour();
   out << tempHour << ":";
   int tempMinute = tom.time.getMinute();
   out << tempMinute << ":";
   int tempSecond = tom.time.getSecond();
   out << tempSecond << " ";
   out << tom.request << " ";
   out << tom.status << " ";
   out << tom.number_of_bytes << " ";

  return out;
}

////////////////////////////////////////////////////////// 
// output_all method
// REQUIRES:  a stream and a vector of LogEntries
//ENSURES:   all members of each LogEntry is outputed
void output_all(std::ostream& out, const std::vector<LogEntry> &tom) {
  for(unsigned long int i = 0; i < tom.size(); ++i)
    out << tom[i] << std::endl;
}

////////////////////////////////////////////////////////// 
// by_host methond
//REQUIRES:  a stream and a vector of LogEntries 
// ENSURES:  the host of each LogEntry is outputed
void by_host(std::ostream& out, const std::vector<LogEntry>&tom) {
  for (unsigned long int i = 0; i < tom.size(); ++i){
    LogEntry temp = tom[i];
    out << tom[i].getHost() << std::endl;
  }
}

////////////////////////////////////////////////////////// 
// byte_count method
// Requires:  a vector of LogEntries
//ENSURES:  the sum of the bytes are returned
int byte_count(const std::vector<LogEntry> &tom) {
  int result = 0;
  for (unsigned long int i = 0; i < tom.size(); ++i)
    if(tom[i].getNumber_of_bytes() >= 0)
       result = result + tom[i].getNumber_of_bytes();
    return result;
} 

