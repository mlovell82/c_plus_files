#include <iostream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include "ASTree.hpp"

void foo(srcML);

int main(){

  {
    
    srcML tom;
    
    // Used for mainHeader() test
    std::vector<std::string> passer;
    passer.push_back("simple.cpp");    
    
    //Used for fileHeader() test
    std::string passer2 = "simple.cpp";

std::ifstream file("simple.cpp.xml");
    if(!file){
      std::cerr << "could not open file" << std::endl;
      exit(1);
    }
    
    
    file >> tom;

    // Used for copyconstructor test
    //    std::cout << "this is copied srcML object" << std::endl;
    //    foo(tom);

    tom.mainHeader(passer);
    tom.funcCount(passer2);
    tom.mainReport(passer);
    tom.lineCount(passer2);
    //tom.fileHeader(passer);
    std::cout << "this is original srcML object" << std::endl;

    //std::ofstream out;
    std::cout << tom << std::endl;
    
  
}


}
void foo(srcML dick){
  std::ofstream out;
  std::cout << dick << std::endl;
}
