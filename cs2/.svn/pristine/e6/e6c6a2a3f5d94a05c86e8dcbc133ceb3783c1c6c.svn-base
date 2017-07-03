// Michael Lovell
// cs23001 lab7

#include<iostream>
#include<string>
#include<fstream>

void getWord(std::ifstream & in, std::string &word){
  in >> word;
  }

void getLine(std::ifstream & in, std::string &line){
  std::getline(in, line);
  }

int main(int argc, char * argv[]){

  // Call getWord  
std::ifstream file ("debugandiotestfile.txt");
 if(!file.is_open()){
   std::cout << "Unable to open file 1\n";
   return 1;
 }
 std::string word;
  while(!file.eof()){
    getWord(file, word);
    }

  file.close();

  // Call getLine
  std::ifstream file2 ("debugandiotestfile.txt");
  if(!file2.is_open()){
    std::cout << "Unable to open file 2\n";
   return 1;
  }  
  std::string line;
  while(!file2.eof()){
   getLine(file2, word);
  }
  file.close();
}
