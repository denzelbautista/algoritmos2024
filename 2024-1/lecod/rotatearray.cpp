#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v1 = {1, 2, 3, 4};
  v1.push_back(2);

  cout << "size: " << v1.size() << endl;
  for (int i = 0; i < v1.size(); i++) {
    cout << v1[i] << endl;
  }

  return 0;
}