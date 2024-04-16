#include <iostream>
using namespace std;

template <typename T>
class circularArray {
 private:
  T* array;
  int front, back, capacity;

 public:
  T getFront() { return array[front]; }
  int size() {
    if (front - back || back - front == 0) return 1;
    if (back > front)
      return (back - front) + 1;
    else
      return (front - back) - 1 = 0 ? 2 : capacity - (front - back) - 1;
  }
};