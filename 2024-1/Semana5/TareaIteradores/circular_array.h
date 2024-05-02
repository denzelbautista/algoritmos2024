#include <iostream>
using namespace std;

template <class T>
class CircularArray {
 private:
  T* array;
  int capacity;
  int back, front;

 public:
  CircularArray();
  CircularArray(int _capacity);
  virtual ~CircularArray();
  void push_back(T data);
  void push_front(T data);
  bool is_full();
  bool is_empty();

 private:
  int next(int);
  int prev(int);
  friend class ArrayCIterator<T>;
};

template <class T>
class ArrayCIterator {
 private:
  int current;
  CircularArray<T>* carray;

 public:
  ArrayCIterator() {}
  ArrayCIterator(int current, CircularArray<T>* carray) {
    this->current = current;
    this->carray = carray;
  }
};

template <class T>
CircularArray<T>::CircularArray() {
  CircularArray(0);
}

template <class T>
CircularArray<T>::CircularArray(int _capacity) {
  this->array = new T[_capacity];
  this->capacity = _capacity;
  this->front = this->back = -1;
}

template <class T>
CircularArray<T>::~CircularArray() {
  delete[] array;
}

template <class T>
int CircularArray<T>::prev(int index) {
  return (index == 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index) {
  return (index + 1) % capacity;
}

template <class T>
void CircularArray<T>::push_back(T data) {
  if (is_full()) throw "The array is full";
  if (is_empty())
    front = back = 0;
  else
    back = next(back);
  array[back] = data;
}

template <class T>
void CircularArray<T>::push_front(T data) {
  if (is_full()) throw "The array is full";
  if (is_empty())
    front = back = 0;
  else
    front = prev(front);
  array[front] = data;
}

template <class T>
bool CircularArray<T>::is_empty() {
  return front == -1;
}

template <class T>
bool CircularArray<T>::is_full() {
  return front == next(back) && !is_empty();
}
