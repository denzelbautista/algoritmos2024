#include <iostream>
using namespace std;

template <typename T>
struct Node {
  T data;
  Node<T>* parent = nullptr;
  int nodeRank = 0;
};

int main() { return 0; }