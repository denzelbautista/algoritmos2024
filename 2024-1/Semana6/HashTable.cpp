#include <iostream>
using namespace std;

class HashTable {
 private:
  struct Node {
    string key;
    int value;
    Node* next;
  };

  Node** array;  // el arrray de nodos
  int capacity;  // tamanio del array
  int count;     // total de elementos

 public:
  ~HashTable() { delete[] array; }

  HashTable() {
    capacity = 5;
    array = new Node*[capacity];
  }
  void set(string key, int value) {
    // aqui se llama al rehashing
  }

  int get(string key) {}

  void display() {}

 private:
  void rehashing() {}  // redimensionar y reubicar los elemntos cuando se excede
                       // la maxima colision
};