#include <iostream>
#include <list>
#include <string>


int main(){

  std::list<std::string> stooges;
  stooges.push_back("moe");
  stooges.push_back("larry");
  stooges.push_back("curly");
  std::cout << "original list" << std::endl;
  for(std::list<std::string>::iterator i = stooges.begin(); i != stooges.end(); ++i)
    std::cout << *i << " " << std::endl;

  std::list<std::string>::iterator j = stooges.begin();
  
  while (*j != "larry") 
    ++j;
  std::cout << "larry found" << std::endl;
  std::cout << "shemp inserted before larry" << std::endl;
  stooges.insert(j, "shemp");
  for(std::list<std::string>::iterator i = stooges.begin(); i != stooges.end(); ++i)
    std::cout << *i << " " << std::endl;
  ++j;

  std::cout << "curly_joe insterted after larry" << std::endl;
  stooges.insert(j, "curly_joe");
  for(std::list<std::string>::iterator i = stooges.begin(); i != stooges.end(); ++i)
    std::cout << *i << " " << std::endl;

}
