// collection.h
// Michael Lovell
// CS3
// 9/23/2016

#ifndef COLLECTION_H
#define COLLECTION_H
#include <iostream>
#include <typeinfo>

template <typename T>
class node{
public:

  node(): next_(nullptr) {}

  // functions can be inlined
  T getData()const{return data_;}
  void setData(const T& data){data_=data;}

  // or can be defined outside

  node<T>* getNext() const;
  void setNext(node<T> *const);

private:
  T data_;
  node<T> *next_;
};

template <typename T>
class Collection{
public:
  Collection(int size=0): size_(size), collectionNode_(size > 0 ? new node<T>[s\
ize] : nullptr){}
  Collection(const Collection<T>&);
  ~Collection(){delete[] collectionNode_;}
  Collection& operator=(const Collection<T>&);
  void  addItem(T addedData);
  void  removeItem(T removeData);
  T   lastItem();
  void  printCollection();
  private:
  node<T>* collectionNode_;
  int size_;
  };

template<>
void Collection::printCollection<Collection>;

template <typename T>
node<T>* node<T>::getNext()const{
  return next_;
}

template<typename T>
void node<T>::setNext(node<T> *const next){
  next_=next;
}

// first "if" handles empty objects, "else" handles objects with nodes.
//addedItem is put in the back element and int oldSize is used to fill old coll\
ection into new sized collection object
template<typename T>
void Collection<T>::addItem(T addedData){
    if(size_ == 0){
      ++size_;
      collectionNode_ = new node<T>[size_];
      collectionNode_[0].setData(addedData);
      collectionNode_[0].setNext(nullptr);
    } else {

      int oldSize = size_;
      ++size_;
      node<T>* temp = new node<T>[size_];
      temp[size_ - 1].setData(addedData);
      temp[size_ - 1].setNext(collectionNode_);
      for(int i = 0; i < oldSize; ++i){
        temp[i].setData(collectionNode_[i].getData());
        temp[i].setNext(&collectionNode_[i + 1]);
       }
    delete [] collectionNode_;
    collectionNode_ = temp;
    }
}


template<typename T>
void Collection<T>::printCollection(){
 for(int i = 0; i < size_; ++i)
   std::cout << collectionNode_[i].getData() << " ";
  std::cout << std::endl;
}
template<typename T>
void Collection<Collection<T>>::printCollection(){

    Collection temp;
    for(int i = 0; i < size_; ++i){
      temp = collectionNode_[i].getData;
      temp.printCollection();
    }
  }

template<typename T>
Collection<T>& Collection<T>::operator=(const Collection<T>& swapee){
  if(collectionNode_ == swapee.collectionNode_)
    return *this;
  Collection<T> temp;
  temp.size_ = swapee.size_;
  temp.collectionNode_ = new node<T>[temp.size_];
  for(int i = 0; i < temp.size_; ++i){
    temp.collectionNode_[i].setData(swapee.collectionNode_[i].getData());
    temp.collectionNode_[i].setNext(swapee.collectionNode_[i].getNext());
  }
  return *this;
}

template<typename T>
Collection<T>::Collection(const Collection<T> &actual):Collection(){

  size_ = actual.size_;
  collectionNode_ = new node<T>[size_];
  for(int i = 0; i < size_; ++i){
    collectionNode_[i].setData(actual.collectionNode_[i].getData());
    collectionNode_[i].setNext(actual.collectionNode_[i].getNext());
  }
}

// first for loop checks to see if data is in collection.
// 2nd for removes data from collection
template<typename T>
void Collection<T>::removeItem(T removeData){
  bool found = false;
  for(int i = 0; i < size_; ++i)
    if(collectionNode_[i].getData() == removeData)
      found = true;
  if(found){
    int oldSize = size_, j = 0;
    --size_;
    node<T>* temp = new node<T>[size_];
    for(int i = 0; i < oldSize; ++i){
      if(collectionNode_[i].getData() != removeData){
        temp[j].setData(collectionNode_[i].getData());
        ++j;
      }
    }
    delete [] collectionNode_;
    collectionNode_ = temp;
  }
}

template<typename T>
T Collection<T>::lastItem(){
   T result = collectionNode_[size_ - 1].getData();
   return result;
}
#endif
