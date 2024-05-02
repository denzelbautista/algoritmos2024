#include <iostream>

#include "simple_array.h"

using namespace std;

int main() {
  Array<int> arr({2, 4, 6, 8, 10, 12});

  Array<int>::iterator ptr;

  for (ptr = arr.begin(); ptr != arr.end(); ++ptr) cout << *ptr << "\n";

  return 0;
}