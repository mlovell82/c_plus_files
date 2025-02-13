// test_move_swap
// Michael Lovell
// 3/31/2016
// cs23001

#include<iostream>
#include"stack.hpp"
#include"string/string.hpp"
#include<cassert>

int main(){

  {
    // Swap() test
    stack<int> one, two;
    one.push(5);
    two.push(3);
    one.swap(two);
    assert(one.getTos() == 3);
    assert(two.getTos() == 5);
  }
  
  {
    // Swap() test with differing # of ints
    stack<int> one, two;
    one.push(567);
    two.push(3);
    one.swap(two);
    assert(one.getTos() == 3);
    assert(two.getTos() == 567);
  }

  {
    // Swap test with Strings
    stack<String> one, two;
    one.push("job");
    one.push("well");
    two.push("done");
    one.swap(two);
    assert(one.getTos() == "done");
    assert(two.getTos() == "well");
  }

  {
    // test push of more than 1 data
    stack<int> one;
    one.push(1);
    one.push(2);
    assert(one.getTos() == 2);  
  }

  {
    // test swap with defaults
    stack<int> one;
    stack<int> two;
    one.swap(two);
  }

  {
    // test swap with a default and a 1 item stack
    stack<int> one;
    stack<int> two;
    one.push(1);
    one.swap(two);
       
    assert(two.getTos() == 1);
  }

  {
  // test swap with a default and a more than 1 item stack
  stack<int> one;
  stack<int> two;
  one.push(1);
  one.push(2);
  one.swap(two);

  assert(two.getTos() == 2);
  }
  
  {
    // test swap with a more than 1 stack and a more than 1 item stack
    stack<int> one;
    stack<int> two;
    one.push(1);
    one.push(2);
    two.push(3);
    two.push(4);
    one.swap(two);
    assert(one.getTos() == 4);
    assert(two.getTos() == 2);
  }
  
  {
    // move constructor
    stack<int> two;
    two.push(1);
    stack<int> one(two);
    assert(one.getTos() == 1);
  }

  {
    // test pop method
    stack<int> one;
    one.push(1);
    one.push(2);
    one.pop();
    assert(one.getTos() == 1);
}

}
