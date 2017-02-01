// Wordcount header file
// CS3
// Michael Lovell
// 9/13/2016

#ifndef WORDCOUNT_HPP
#define WORDCOUNT_HPP
#include <iostream>
#include <string>

class WordOccurrence {
public:
  WordOccurrence(const std::string& word="", int num=0): word_(word), num_(num)\
{}
  bool matchWord(const std::string&);
  void increment(){++num_;}
  std::string getWord()const{return word_;}
  int getNum()const{return num_;}
  void setWord(const std::string addedWord){word_ = addedWord;}
  void setNum(const int changeNum){num_ = changeNum;}
private:
  std::string word_;
  int num_;
};

class WordList{
public:
  WordList(int size=0):size_(size), wordArray_(size > 0 ? new WordOccurrence[si\
ze] : nullptr){}
  WordList(const WordList& copiedList);
  ~WordList(){delete[] wordArray_;}
  WordList& operator=(WordList copiedList);
  friend void swap(WordList&, WordList&);
  void addWord(const std::string&);
  void printList();
  void sort();
private:
  WordOccurrence *wordArray_;
  int size_;
};
#endif
