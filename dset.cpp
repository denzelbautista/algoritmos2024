// Homework Disjoint Set
#include <iostream>
using namespace std;

template <typename T>
struct Node {
  T data;
  Node<T> *parent = nullptr;
  int nodeRank = 0;
  Node() {}
  Node(T t) { data = t; }
};

template <typename T>
class DisjointSet {
 public:
  void makeSet(Node<T> *x) { x->parent = x; }

  Node<T> *find(Node<T> *x) {
    if (x->parent != x) {
      x->parent = find(x->parent);
    }
    return x->parent;
  }

  void setUnion(Node<T> *x, Node<T> *y) {
    Node<T> *xRoot = find(x);
    Node<T> *yRoot = find(y);

    if (xRoot == yRoot) return;

    if (xRoot->nodeRank < yRoot->nodeRank) {
      xRoot->parent = yRoot;
    } else if (xRoot->nodeRank > yRoot->nodeRank) {
      yRoot->parent = xRoot;
    } else {
      yRoot->parent = xRoot;
      xRoot->nodeRank++;
    }
  }

  bool isConnected(Node<T> *x, Node<T> *y) {
    Node<T> *xRoot = find(x);
    Node<T> *yRoot = find(y);
    return xRoot == yRoot ? true : false;
  }
};

int main() {
  Node<int> *a = new Node(1);
  Node<int> *b = new Node(2);
  Node<int> *c = new Node(3);
  Node<int> *d = new Node(4);

  DisjointSet<int> dj;
  dj.makeSet(a);
  dj.makeSet(b);
  dj.makeSet(c);
  dj.makeSet(d);

  dj.setUnion(a, b);
  dj.setUnion(c, d);

  cout << dj.isConnected(a, b) << endl;
  cout << dj.isConnected(c, b) << endl;

  return 0;
}