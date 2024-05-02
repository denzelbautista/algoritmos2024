#include <iostream>

#include "circular_array_ite.h"

using namespace std;

int main() {
  CircularArray<int> arr(5);
  arr.push_back(2);
  arr.push_back(4);
  arr.push_back(6);
  arr.push_front(10);
  arr.push_front(12);

  CircularArray<int>::iterator ptr;

  for (ptr = arr.begin(); ptr != arr.end(); ++ptr) cout << *ptr << "\n";
  // 12,10,2,4,6

  return 0;
}