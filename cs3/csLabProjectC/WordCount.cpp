// wordcount implementation file
// CS3

// Michael Lovell
// 9/13/2016

#include "wordCount.hpp"
#include <iostream>
#include <string>


WordList::WordList(const WordList& copiedWordList){
  size_ = copiedWordList.size_;
  wordArray_ = new WordOccurrence[size_];
  for(int i = 0; i < size_; ++i)
    wordArray_[i] = copiedWordList.wordArray_[i];
}

/* Precondition:  called by a WordList object and passes a string to add to the\
 list
   Postcondition:  if words in the list, occurrence number is incremented and s\
ort is called; else
   wordArray_ expanded 1 element and new string is added to the last element*/
void WordList::addWord(const std::string& wordToAdd){
  bool addIt = true;
    for(int i = 0; i < size_; ++i)
      if(wordArray_[i].matchWord(wordToAdd)){

        wordArray_[i].increment();
        addIt = false;
        this->sort();
      }
    int backElement = size_;
    if(addIt){
      ++size_;
      WordOccurrence* temp = new WordOccurrence[size_];
      std::copy(wordArray_, wordArray_ + backElement, temp);
      delete [] wordArray_;
      wordArray_ = temp;
      wordArray_[backElement].setWord(wordToAdd);
      wordArray_[backElement].increment();
       }
  }


void WordList::printList(){
  for(int i = 0; i < size_; ++i){
    std::cout << wordArray_[i].getWord() << "\t" << wordArray_[i].getNum() << s\
td::endl;
  }
}

bool WordOccurrence::matchWord(const std::string& wordToCompare){
  if(word_ == wordToCompare)
    return true;
  else
    return false;
}

void swap(WordList& firstWord, WordList& secondWord){
  std::swap(firstWord.size_, secondWord.size_);
  std::swap(firstWord.wordArray_, secondWord.wordArray_);
}

WordList& WordList::operator=(WordList copiedList){
  swap(*this, copiedList);
  return *this;
}

/* Precondition:  called by WordList when already occuring word is found again \
and occurenc number is incremented
   Postcondition:  uses temp variable standard sort algorithm with two temps 1 \
for the word and 1 for its int*/
void WordList::sort(){
  std::string tempString;
  int tempInt;
  for(int i = 0; i < size_; ++i){
    if(wordArray_[size_ -1].getNum() >= wordArray_[i].getNum()){
      tempString = wordArray_[i].getWord();
      tempInt = wordArray_[i].getNum();
      wordArray_[i].setWord(wordArray_[size_ - 1].getWord());
      wordArray_[i].setNum(wordArray_[size_ - 1].getNum());
      wordArray_[size_ - 1].setWord(tempString);
      wordArray_[size_ - 1].setNum(tempInt);
    }
  }
}
