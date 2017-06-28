// Created by Michael Lovell
// 10/24/2016

#include<fstream>
#include<iostream>
#include<string>

#ifndef LOGGER_HPP
#define LOGGER_HPP
class Logger{
public:
  static Logger* instance(){
    static Logger s;
    return &s;
  }
  void report(const std::string& line){file_ << line ; file_ << "\n";}
  ~Logger(){file_.flush(); file_.close();}

private:
  Logger(){
    file_.open("log.txt");
  }
  Logger(const Logger&){}
  Logger& operator=(const Logger&);

  std::ofstream file_;
};

#endif
