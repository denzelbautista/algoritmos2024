#include <iostream>
using namespace std;

struct node {
  int data;
  node* next;
  node() {}
  node(int _data, node* _next = nullptr) {
    data = _data;
    next = _next;
  }
  // otra forma
  // node(int _data, node* _next) : data(_data),next(_next){}
};

class fwdlist {
 private:
  node* head;

 public:
};

int main() { return 0; }