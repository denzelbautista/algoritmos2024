#include <iostream>
using namespace std;
template <typename TK, typename TV>
class HashTable {
 private:
  struct Pait {
    TK key;
    TV value;
    Pair(TK _k, TV _v) {
      key = _k;
      value = _v;
    }
  };

  ForwardList<Pait> *array;  // el arrray de nodos
  int capacity;              // tamanio del array
  int count;                 // total de elementos
  std::hash<TK> fhash;

 public:
  HashTable() {
    capacity = 5;
    array = new F *[capacity];
  }
  void set(TV key, TV value) {
    size_t hash_code = fhash(key);
    int index = hash_code % capacity;
    // verificar si existe, se sobreescribe el valor
    // codigo aqui
    //

    //// aqui se llama al rehashing
    if (array[index].size() == MAX_COL) {
      rehashing();
      index = hash_code % capacity;
    }
    array[index].push_front(Pair(key, value));
  }

  int get(string key) {}

  void display() {}

 private:
  void rehashing() {}  // redimensionar y reubicar los elemntos cuando se excede
                       // la maxima colision
};