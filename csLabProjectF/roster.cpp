// vector and list algorithms
// Mikhail Nesterenko
// 3/11/2014

#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>
#include <map>
#include <utility>
#include <algorithm>

using std::ifstream;
using std::string; using std::getline;
using std::list; using std::vector;
using std::cout; using std::endl;
using std::move; using std::map;

// reading a list from a fileName
void readRoster(map<string, list<string>>&, string);
// printing a list out

void printRoster(const map<string, list<string>>);
void printList(const list<string>);
void parseRoster(map<string, list<string>>&);
int main(int argc, char* argv[]){

  if (argc <= 1){ cout << "usage: " << argv[0]
                       << " list of courses, dropouts last" << endl; exit(1);}
  cout << "All Students" << endl;
  cout << "last name, first name:  course enrolled" << endl;
  std::map<string, list<string>> studentEntries;
  // reading in rosters per course and printing them out
  for(int i=1; i < argc; ++i){
    readRoster(studentEntries, argv[i]);
  }
    parseRoster(studentEntries);
    printRoster(studentEntries);

}

void readRoster(map<string, list<string>>& paramList, string fileName){
  ifstream course(fileName.c_str());
  string first, last, name;
  fileName = fileName.erase(3,4);

  while(course >> first >> last){
    name = first + " " + last;
    list<string> newCourse;
    fileName.erase(fileName.begin()+4, fileName.end());
    newCourse.push_back(fileName);

    auto it = paramList.find(name);
    if(it != paramList.end())
      it->second.push_back(fileName);
    else
      paramList[name] = newCourse;

  }
}
void printRoster(const map<string, list<string>> roster){
  for(const auto& e: roster){
    cout << e.first << ": ";
    printList(e.second);
    cout << endl;
  }
}

void printList(const list<string> courses){

  for(auto const it: courses) cout << it << " ";
}

 void parseRoster(map<string, list<string>>& paramList){
   bool cs4Present = false, otherCs = false;
   string wantedVal = "cs4";
   for(auto& it: paramList){
     cs4Present = false;
     otherCs = false;
     for(auto& e : it.second){
        if(e[0] == 'c' && e[1] == 's' && e[2] == '4')
          cs4Present = true;
        else
          otherCs = true;
     }
   string name = it.first;
   if((cs4Present) && (otherCs)){
     paramList.erase(name);

     }
   }
 }
