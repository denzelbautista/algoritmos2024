#include <iostream>
using namespace std;

template <typename T>
class ForwardList {
 private:
  struct Node {
   private:
    T data;
    Node* next;
    Node() {}
    Node(int _data, Node* next = nullptr) : data(_data), next(_next) {}
  }
};

int main() { return 0; }