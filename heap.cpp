#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &vec, int a, int b) {
  int temp = vec[a];
  vec[a] = vec[b];
  vec[b] = temp;
}

void heapify_up(vector<int> &h) {
  int i = h.size() - 1;  // se obtiene el índice del último elemento
  while (i > 0 && h[i] < h[(i - 1) / 2]) {
    swap(h, i, (i - 1) / 2);
    i = (i - 1) / 2;
  }
}

void insert(vector<int> &heap, int data) {
  heap.push_back(data);  // se añade el nuevo elemento al final del vector
  heapify_up(heap);  // se llama a la función heapify_up para reubicar el nuevo
                     // elemento
}

void heapify_max(vector<int> &h, int i, int n) {
  // h es el vector que se quiere convertir en heap
  // i es el índice del elemento que se quiere heapify
  // n es el tamaño del vector o del subvector que se quiere heapify
  int mayor = i;        // se asume que el elemento es el mayor
  int izq = 2 * i + 1;  // se calcula el índice del hijo izquierdo
  int der = 2 * i + 2;  // se calcula el índice del hijo derecho

  // se verifica si el hijo izquierdo existe y es mayor que el elemento
  if (izq < n && h[izq] > h[mayor]) {
    mayor = izq;  // se actualiza el índice del mayor
  }

  // se verifica si el hijo derecho existe y es mayor que el elemento
  if (der < n && h[der] > h[mayor]) {
    mayor = der;  // se actualiza el índice del mayor
  }

  // se verifica si el mayor no es el elemento
  if (mayor != i) {
    // se intercambia el elemento con el mayor de sus hijos
    swap(h, i, mayor);

    // se llama recursivamente a la función con el índice del mayor
    heapify_max(h, mayor, n);
  }
}
void heapify_min(vector<int> &h, int i, int n) {
  // h es el vector que se quiere convertir en heap
  // i es el índice del elemento que se quiere heapify
  // n es el tamaño del vector o del subvector que se quiere heapify
  int mayor = i;        // se asume que el elemento es el mayor
  int izq = 2 * i + 1;  // se calcula el índice del hijo izquierdo
  int der = 2 * i + 2;  // se calcula el índice del hijo derecho

  // se verifica si el hijo izquierdo existe y es mayor que el elemento
  if (izq < n && h[izq] < h[mayor]) {
    mayor = izq;  // se actualiza el índice del mayor
  }

  // se verifica si el hijo derecho existe y es mayor que el elemento
  if (der < n && h[der] < h[mayor]) {
    mayor = der;  // se actualiza el índice del mayor
  }

  // se verifica si el mayor no es el elemento
  if (mayor != i) {
    // se intercambia el elemento con el mayor de sus hijos
    swap(h, i, mayor);

    // se llama recursivamente a la función con el índice del mayor
    heapify_min(h, mayor, n);
  }
}

int main() {
  vector<int> hip{10, 19, 42, 31, 27, 14, 26, 33, 44, 35};
  int n = hip.size();  // se obtiene el tamaño del vector

  // se llama a la función heapify_down desde el último elemento que no es una
  // hoja hasta el primer elemento
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify_min(hip, i, n);
  }
  // se imprime el vector resultante, que debería ser un heap máximo
  for (int i = 0; i < hip.size(); i++) {
    cout << hip[i] << ", ";
  }
  cout << endl;

  insert(hip, 5);

  // se imprime el vector resultante, que debería ser un heap máximo
  for (int i = 0; i < hip.size(); i++) {
    cout << hip[i] << ", ";
  }
  cout << endl;

  return 0;
}
