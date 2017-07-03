// Michael Lovell
// Recursion practice
// March 8, 2016

#include <iostream>

int fibonacci(int);
int fibonacci_tail(int,int,int);

int main(){
  int number = 10;

 for(int i = 0; i <= number; ++i)
  std::cout << fibonacci(i) << ", ";

 std::cout << std::endl;

 for(int i = 0; i <= number; ++i)  
   std::cout <<  fibonacci_tail((i), (1), (0)) << ", ";    
    
  
}

int fibonacci(int number){
  if(number < 2)
    return  number;
  else
    return fibonacci(number - 1) + fibonacci(number - 2);
}

int fibonacci_tail(int number, int prev_number, int last_number){
  if(number == 0)return last_number;
  if(number == 1)return prev_number;
  return fibonacci_tail(number - 1, prev_number + last_number, prev_number);
  
}
