#include <iostream>
using namespace std;

/*
int main() {
  int ***r, **q, *p, i = 8;
  p = &i;
  (*p)++;
  q = &p;
  (**q)++;
  r = &q;
  cout << *p << " " << **q << " " << ***r;
  return 0;
}
*/
/*

int main() {
    // OPERADOR DE PRE INCREMENTO
  int x = 10, a;
  a = ++x;  // Incrementa x antes de usarlo en la expresión
  cout << "Pre Increment Operation" << endl;
  cout << "a = " << a << endl;  // a será 11
  cout << "x = " << x << endl;  // x también será 11
  return 0;
}

*/

void imprimir(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

#include <iostream>
using namespace std;

int main() {
  int arr[5] = {1, 2, 3, 4, 5};
  int *ptr = arr;
  cout << *ptr << endl;
  imprimir(arr, 5);
  cout << "valor de ptr " << *ptr << endl;
  cout << *ptr++ << endl;
  imprimir(arr, 5);
  cout << "valor de ptr " << *ptr << endl;
  cout << *++ptr << endl;
  imprimir(arr, 5);
  cout << "valor de ptr " << *ptr << endl;
  cout << ++*ptr << endl;
  imprimir(arr, 5);
  cout << "valor de ptr " << *ptr << endl;
  cout << (*ptr)++ << endl;
  imprimir(arr, 5);
  cout << "valor de ptr " << *ptr << endl;
  cout << *ptr << endl;
  imprimir(arr, 5);
}
