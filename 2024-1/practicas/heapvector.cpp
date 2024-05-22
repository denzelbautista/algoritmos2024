// C++ code to demonstrate the working of
// make_heap(), front()
#include <bits/stdc++.h>
using namespace std;

void print(vector<int>& vc) {
  for (auto i : vc) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  // Initializing a vector
  vector<int> v1 = {20, 30, 40, 25, 15};

  // Converting vector into a heap
  // using make_heap()
  make_heap(v1.begin(), v1.end(), greater<int>());

  // Displaying the maximum element of heap
  // using front()
  cout << "The minimum element of heap is : ";
  cout << v1.front() << endl;

  print(v1);

  v1.push_back(5);
  push_heap(v1.begin(), v1.end(), greater<int>());

  cout << "The minimum element of heap is : ";
  cout << v1.front() << endl;

  print(v1);

  pop_heap(v1.begin(), v1.end(), greater<int>());

  print(v1);

  return 0;
}
