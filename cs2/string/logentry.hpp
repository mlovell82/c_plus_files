#ifndef CS_LOGENTRY_H_
#define CS_LOGENTRY_H_

////////////////////////////////////////////////////////////
//
// File:        logentry.hpp 
//       
// Version:     1.0
// Date: 3/27/2016       
// Author: Michael Lovell     
// cs23001
// Description: Class definition for a log entry.
//
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

#include "string.hpp" 

////////////////////////////////////////////////////////////
class Date { 
public:
  Date(): day(0), month(0), year(0) {};
  void setDate(String, String,int);
  String getDay()const{return day;};
  String getMonth()const{return month;};
  int getYear()const{return year;};
private:
    String  day, month;
    int     year;
};

////////////////////////////////////////////////////////////
class Time {
  public:
  Time(): hour(0), minute(0), second(0) {};
  void setTime(int, int, int);
  int getHour()const{return hour;};
  int getMinute()const{return minute;};
  int getSecond()const{return second;};
  private:
    int     hour, minute, second;
};


////////////////////////////////////////////////////////////
class LogEntry : public Date, public Time {
public:
            LogEntry() {};
            LogEntry(String);
    friend  std::ostream& operator<<(std::ostream&, const LogEntry&);
  String getHost()const{return host;};
  int getNumber_of_bytes()const{return number_of_bytes;};
private:
    String  host;
    Date    date;
    Time    time;
    String  request;
    String  status;
    int     number_of_bytes;
};


////////////////////////////////////////////////////////////
//
// Free functions
//

std::vector<LogEntry>   parse       (std::istream&);
void                    output_all  (std::ostream&, const std::vector<LogEntry> &);
void                    by_host     (std::ostream&, const std::vector<LogEntry> &);
int                     byte_count  (const std::vector<LogEntry>&);

#endif

