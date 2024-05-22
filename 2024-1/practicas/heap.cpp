#include <iostream>
#include <vector>

using namespace std;

#include <iostream>
#include <vector>

using namespace std;

class Heap {
 private:
  struct HeapNode {
    int val;
    HeapNode *left;
    HeapNode *right;
    HeapNode() : val(0), left(nullptr), right(nullptr) {}
  };

  HeapNode *head;

  // Función para ajustar el heap hacia arriba después de insertar un elemento
  void heapifyUp(HeapNode *node) {
    if (!node || !node->left) return;

    HeapNode *parent = node;
    while (parent->left) {
      HeapNode *largestChild = parent->left;
      if (parent->right && parent->right->val > largestChild->val) {
        largestChild = parent->right;
      }

      if (largestChild->val > parent->val) {
        swap(parent->val, largestChild->val);
        parent = largestChild;
      } else {
        break;
      }
    }
  }

  // Función para ajustar el heap hacia abajo después de eliminar un elemento
  void heapifyDown(HeapNode *node) {
    if (!node) return;

    HeapNode *largestChild = node->left;
    if (node->right && node->right->val > largestChild->val) {
      largestChild = node->right;
    }

    if (largestChild && largestChild->val > node->val) {
      swap(node->val, largestChild->val);
      heapifyDown(largestChild);
    }
  }

 public:
  Heap() : head(nullptr) {}  // Inicializa head como nullptr
  // Insertar un elemento en el heap
  void insert(int value) {
    HeapNode *newNode = new HeapNode();
    newNode->val = value;

    if (!head) {
      head = newNode;
    } else {
      // Insertar en el siguiente nodo disponible (siguiendo la propiedad del
      // heap) y luego ajustar el heap hacia arriba (asegurando que el nuevo
      // nodo sea mayor o igual que su padre) Puedes implementar esto según tus
      // necesidades. Aquí, simplemente lo insertamos como hijo izquierdo.
      newNode->left = head->left;
      head->left = newNode;
      heapifyUp(newNode);
    }
  }

  // Eliminar el elemento máximo (raíz) del heap
  void removeMax() {
    if (!head) return;

    // Intercambiar el valor de la raíz con el último nodo
    swap(head->val, head->left->val);

    // Eliminar el último nodo (anteriormente la raíz)
    HeapNode *lastNode = head->left;
    head->left = nullptr;
    delete lastNode;

    // Ajustar el heap hacia abajo desde la raíz
    heapifyDown(head);
  }

  // Heapsort (ordenar el arreglo utilizando el heap)
  vector<int> heapsort() {
    vector<int> sortedArray;
    while (head) {
      sortedArray.push_back(head->val);
      removeMax();
    }
    return sortedArray;
  }
};

int main() {
  Heap heap;
  heap.insert(5);
  heap.insert(10);
  heap.insert(3);
  heap.insert(8);

  cout << "Heapsort result: ";
  vector<int> sorted = heap.heapsort();
  for (int val : sorted) {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}

/*
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
*/