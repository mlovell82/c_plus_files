// vector and list algorithms
// Modified by Michael Lovell
// Originally created by Mikhail Nesterenko
// 9/29/2016

#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <string>

#include <cstdlib>

using std::ifstream;
using std::string; using std::getline;
using std::list; using std::vector;
using std::cout; using std::endl;
using std::move;

// reading a list from a fileName that is not cs4.txt
void readNotCS4(list<string>& roster, string fileName);
// reading a list from a fileName that is cs4.txt
void readCS4(list<string>& roster, string fileName);
// printing a list out
void printRoster(const list<string>& roster);

int main(int argc, char* argv[]){

  if (argc <= 1){ cout << "usage: " << argv[0]
                       << " list of courses, dropouts last" << endl; exit(1);}

  // vector of courses of students
  vector <list<string>> cs4Students, notCS4Students;

  // reading in rosters per course and printing them out
  for(int i=1; i < argc-1; ++i){
    list<string> roster;
    readNotCS4(roster, argv[i]);

    notCS4Students.push_back(move(roster));
    roster.clear();
  }

  for(int i=1; i < argc; ++i){
    list<string> roster;
    readCS4(roster, argv[i]);

    cs4Students.push_back(move(roster));
    roster.clear();
  }

  list<string> cs4StudentsOnly;
  for(auto& e : cs4Students)
    cs4StudentsOnly.splice(cs4StudentsOnly.end(), e);

  cs4StudentsOnly.sort();

cs4StudentsOnly.unique();
  list<string> allStudents;  // master list of students

  for(auto& lst : notCS4Students)
    allStudents.splice(allStudents.end(),lst);

  allStudents.sort(); // sorting master list

  allStudents.unique(); // eliminating duplicates

  for(auto i = allStudents.begin(); i != allStudents.end(); ++i)
    for(auto j = cs4StudentsOnly.begin(); j != cs4StudentsOnly.end(); ++j)
      if(*i == *j){
        i = allStudents.erase(i);
        j = cs4StudentsOnly.erase(j);
        --j;
      }

  auto it = allStudents.begin();
  allStudents.splice(it, cs4StudentsOnly);
  allStudents.sort();

  cout << "Master class list with dropouts removed" << endl;

  printRoster(allStudents);
}

// reading a list from fileName for cs1, cs2, or cs3
void readNotCS4(list<string>& roster, string fileName){
  ifstream course(fileName.c_str());
  string first, last;
  if(fileName != "cs4.txt")
  while(course >> first >> last)
    roster.push_back(first + ' ' + last);
  course.close();
}

// reading a list from fileName for cs4
void readCS4(list<string>& roster, string fileName){
  ifstream course(fileName.c_str());
  string first, last;
  if(fileName == "cs4.txt")
    while(course >> first >> last)
      roster.push_back(first + ' ' + last);
  course.close();
}

// printing a list out
void printRoster(const list<string>& roster){
  for(const auto& str : roster)
    cout << str << endl;
}
