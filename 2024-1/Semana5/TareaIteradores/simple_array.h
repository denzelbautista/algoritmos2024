#include <initializer_list>
#include <iostream>
using namespace std;

template <class T>
class ArrayIterator {
 private:
  int current;
  T* array;

 public:
  ArrayIterator() {}
  ArrayIterator(int current, T* array) {
    this->current = current;
    this->array = array;
  }
  ArrayIterator& operator++() {
    this->current++;
    return *this;
  }
  ArrayIterator& operator--() {
    this->current--;
    return *this;
  }
  bool operator!=(const ArrayIterator& otro) { return current != otro.current; }
  T operator*() { return array[current]; }
};

template <class T>
class Array {
 private:
  T* array;
  int capacity;
  int nsize;

 public:
  typedef ArrayIterator<T> iterator;
  iterator begin() { return iterator(0, this->array); }
  iterator end() { return iterator(nsize - 1, this->array); }
  Array(int _capacity = 10);
  Array(T* array, int n);
  Array(std::initializer_list<int> list);
  virtual ~Array();
  void push_back(T data);
  T pop_back();
  T& operator[](int);
  int size();
  void display();

 private:
  void resize();
};

template <class T>
Array<T>::Array(int _capacity) {
  this->capacity = _capacity;
  this->nsize = 0;
  this->array = new T[_capacity];
}

template <class T>
Array<T>::Array(T* array, int n) {
  this->capacity = this->size = n;
  this->array = array;
}

template <class T>
Array<T>::Array(std::initializer_list<int> list) {
  this->capacity = list.size();
  this->nsize = 0;
  this->array = new T[this->capacity];
  for (auto element : list) this->array[nsize++] = element;
}

template <class T>
Array<T>::~Array() {
  delete[] array;
}

template <class T>
int Array<T>::size() {
  return this->nsize;
}

template <class T>
void Array<T>::push_back(T data) {
  if (this->nsize >= this->capacity) resize();
  array[this->nsize++] = data;
}

template <class T>
T Array<T>::pop_back() {
  if (this->nsize <= 0) throw "The array is empty";
  return array[this->nsize--];
}

template <class T>
T& Array<T>::operator[](int pos) {
  if (pos < 0 || pos >= this->nsize) throw "index out of range";
  return array[pos];
}

template <class T>
void Array<T>::display() {
  for (int i = 0; i < this->nsize; i++) cout << array[i] << ",";
  cout << endl;
}

template <class T>
void Array<T>::resize() {
  this->capacity = this->capacity * 2;
  int* temp = new int[this->capacity];
  for (int i = 0; i < this->nsize; i++) temp[i] = array[i];
  delete[] array;
  array = temp;
}
