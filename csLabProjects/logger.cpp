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
