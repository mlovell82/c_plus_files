// example use of singleton design pattern
// logger loggs the string to a text file using one instance of the method
// Created by Michael Lovell
// 10/25/2016

#include<iostream>
#include<fstream>
#include<string>
#include"logger.hpp"

void funcA();
void funcB();

int main(){

  Logger::instance()->report("It worked");
  funcA();
  funcB();
}

void funcA(){
  Logger::instance()->report("funcA logged text");
}

void funcB(){
  Logger::instance()->report("funcB logged text");
}
