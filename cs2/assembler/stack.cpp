// stack.cpp
// Michael Lovell
// 3/28/2016
// cs23001

#include <iostream>
#include "stack.hpp"
#include <cassert>
// Copy Constructor
// Requires:  A stack object passed by value
// Ensures:  That a seperate copy of the data is created so the original is not manipulated
template<typename T>
stack<T>::stack(const stack<T> & actual){
  node<T> *temp = actual.tos, *bottom = 0;
  tos = 0;
  while(temp != 0){
    if(tos == 0){
      tos = new node<T>(temp -> data);
      bottom = tos;
    }
    else
      {
	bottom -> next = new node<T>(temp -> data);
	bottom = bottom -> next;
      }
    temp = temp -> next;
  }
}

// Destructor
// Requires:  A stack object going out of scope
// Ensures:  all data is deleted and no memory is leaked
template<typename T>
stack<T>::~stack(){
  while(tos != 0){
    node<T> * temp = tos;
    tos = tos->next;
    delete temp;
  }
}

// Pop() method
// Requires:  A stack object
// Ensures: Deletes node off the top of the stack
template<typename T>
T stack<T>::pop(){
  assert(tos != 0);
  T result = tos->data;
  node<T> * temp = tos;
  tos = tos->next;
  delete temp;
  return result;
}

// Push() method
// Requires: A stack object
// Ensures: new node is added to the linked list
template<typename T>
void stack<T>::push(const T& x){
  node<T>* temp = new node<T>(x);
  temp->next = tos;
  tos = temp;
}

// Swap() method
// Requires: 2 stack objects
// Ensures: members of those objects are swapped with each other
template<typename T>
void stack<T>::swap(stack<T>& rhs){
  node<T> *temp = tos;
  tos = rhs.tos;
  rhs.tos = temp;
}
template<typename T>
T stack<T>::getTos()const{
  T result = tos;
  return result;
}
