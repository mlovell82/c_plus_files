
#include<iostream>
#include<algorithm>
#include<vector>

int main(){

  std::vector<int> v1 = {20, 30, 40, 25, 15};

  make_heap(v1.begin(), v1.end());

  std::cout << "The maximum element of heap is: ";
  std::cout << v1.front() << std::endl;

  v1.push_back(50);

  push_heap(v1.begin(), v1.end());

  std::cout << "The maximum element after insert is: ";
  std::cout << v1.front() << std::endl;

  pop_heap(v1.begin(), v1.end());

  std::cout << "The maximum element of heap after delete is: ";
  std::cout << v1.front() << std::endl;

  sort_heap(v1.begin(), v1.end());

  std::cout << "The heap elements after heapSort:";
  for(int &x : v1)
    std::cout << x << " ";

  return 0;
