
// Main file for project 2
// CS44001
// 9/14/2016
// by Michael Lovell

#include <iostream>
#include <string>
#include <fstream>
#include "wordCount.hpp"

int main(int argc, char *argv[]){
  std::ifstream file1(argv[1]);
  if(!file1.is_open())
    std::cout << "Unable to open file" << std::endl;
  WordList myList;

  /* passes file 1 char at a time; if char is alpha numeric its added; else if \
at end of word
     word is added to list; if not alpha numeric or at end of word, spaces is s\
kipped*/
  while(!file1.eof()){
    std::string tempString;
    char alphaNumeric;
    bool done = false;
    bool alphaNumericFound = false;
    while(!done){
      file1.get(alphaNumeric);
      if(isalnum(alphaNumeric)){
         tempString = tempString + alphaNumeric;
         alphaNumericFound = true;
        } else {
        done = true;
        if(alphaNumericFound)
          myList.addWord(tempString);
         }
    }
  }
  myList.printList();

  file1.close();
}
