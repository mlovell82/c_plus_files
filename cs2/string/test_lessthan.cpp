
//  String class test program
//
//  Tests: XXX
//

#include "string.hpp"
#include <cassert>
#include <iostream>
#include <fstream>
#include "logentry.hpp"
//===========================================================================
int main ()
{/*
  {
    String str("131.123.47.176 - - [18/sept/2002:12:05:25 -0400] Get /~darci/ http/1.0 200 5625");
    LogEntry testLog(str);
    std::cout << testLog;
    String ste("133.123.74.767 - - [20/oct/2010:14:27:08 -0700] \"Get /~mack/ http/2.0\" 400 2727");
    LogEntry testLog2(ste);
    std::vector<LogEntry> buddy;
    buddy.push_back(str);
    buddy.push_back(ste);
    output_all(std::cout, buddy);
    by_host(std::cout, buddy);
    std::cout << byte_count(buddy) << std::endl;
  }
 */  
  
  std::ifstream in("log_4_large.txt");    // Define stream for input
  if(!in) {                           // Make sure it opened correctly.
  std::cerr << "Could not open data1-1.txt, exiting." << std::endl;
  //exit(1);
}
  String one;
  long int loop = 1;
  //Until end of file
  //  while(!in.eof()) {
  while(loop != 2000){    
    in >> one;
    

    //  std::vector<LogEntry> log_entries = parse(in);
    // std::cout << log_entries[0] << std::endl;
    
  //Print out results
  ++loop;
}
  while(loop!= 4000){
    in >> one;
    ++loop;
  }
 
  std::cout << loop;

  in.close();
  

  
}
