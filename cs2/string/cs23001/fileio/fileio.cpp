/*
 * Michael Lovell
 * fileio.cpp
 * cs 23001
 */

#include <iostream>
#include <fstream>

void all_output(char);
void non_whitespace(char);
void two_numbers(char);

int main() {
  char ch = ' ';
  std::ifstream file("Text.txt");
  if (!file.is_open()) {
    std::cout << "Unable to open file\n";
    return 1;
  }
  all_output(ch);

  non_whitespace(ch);

  two_numbers(ch);
}

//Precondition: file.get() used to read each char of the text
//Postcondition: each char read in and outputed whitespace included
void all_output(char ch) {
  std::ifstream file("Text.txt");

  while (!file.eof()) {
    file.get(ch);
    std::cout << ch;
  }
  std::cout << std::endl;
  file.close();
}

//Precondition: file read in with >> to skip the whitespace
//Postcondition: every char read in is printed out
void non_whitespace(char ch) {
  std::ifstream file("Text.txt");
  bool done = false;
  while ((!file.eof()) && (done == false)) {
    file >> ch;
    if (ch != ' ')
      std::cout << ch;
    else
      done = true;
  }
  std::cout << std::endl;
  file.close();
}

//Precondition: 3 arrays and a file read in by the program
//Postcondition:  array a and b read in two numbers and array c outputs the sum
void two_numbers(char ch) {
  std::ifstream file("Text.txt");
  const int size = 150;
  bool done = false;
  
  // initialized arrays
  while ((!file.eof()) && (done == false)) {
    int a[size], b[size], c[size];
    for (int i = 0; i < size; ++i){
      a[i] = -1;
      c[i] = -1;
      b[i] = -1;
    }
    
    //each char of the first number read in
    for (int i = 0; i < size; ++i){
      file.get(ch);
      if ((ch != ' ') && (ch != ';') && (ch != '\n')){
	c[i] = (ch - '0');
      }
      else if ((ch == ' ') || (ch == ';'))
	break;
    }
    int i = 0;

    // each char from first number read into a[] so ones place is in element 0
    for (int j = size; j > 0; --j){
      if (c[j] >= 0)
	if ((c[j] == 1) || (c[j] == 2) || (c[j] == 3) || (c[j] == 4) || (c[j] == 5) || (c[j] == 6) || (c[j] == 7) || (c[j] == 8) || (c[j] == 9) || (c[j] == 0)){
	  a[i] = c[j];
	  ++i;
	}
    }
    for (int i = 0; i < size; ++i)
      if (a[i] < 0)
	a[i] = 0;
    
    // first number is outputed to the screen
    std::cout << "this is number1:  ";
    for (int i = 0; i < size; ++i)
      std::cout << a[i] << ' ';
    std::cout << std::endl;
    
    //c[] is reinitialized to take in the next number 
    for (int i = 0; i < size; ++i)
      c[i] = -1;
    for (int i = 0; i < size; ++i){
      file.get(ch);
      if ((ch != ' ') && (ch != ';') && (ch != '\n')){
	c[i] = (ch - '0');
      }
      else if ((ch == ' ') || (ch == ';'))
	break;
    }
    i = 0;
    for (int j = size; j > 0; --j){
      if (c[j] >= 0)
	if ((c[j] == 1) || (c[j] == 2) || (c[j] == 3) || (c[j] == 4) || (c[j] == 5) || (c[j] == 6) || (c[j] == 7) || (c[j] == 8) || (c[j] == 9) || (c[j] == 0)){
	  b[i] = c[j];
	  ++i;
	}
    }
    for (int i = 0; i < size; ++i)
      if (b[i] < 0)
	b[i] = 0;


    std::cout << "this is number 2:  ";
    for (int i = 0; i < size; ++i)
      std::cout << b[i] << ' ';

    int carry_over = 0;
    for (int i = 0; i < size; ++i){
      int place_holder = a[i] + b[i];
      if ((place_holder + carry_over) < 10){
        c[i] = place_holder + carry_over;
        carry_over = 0;
      }
      else
      {
        c[i] = (place_holder + carry_over) % 10;
        carry_over = place_holder / 10;
      }
    }
    std::cout << std::endl;
    std::cout << "this is the sum of 1 and 2:  ";
    for (int i = 0; i < size; ++i)
      std::cout << c[i] << ' ';
      std::cout << std::endl;

    }
}
