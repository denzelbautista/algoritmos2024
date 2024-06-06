#include <iostream>
using namespace std;

template <typename T>
class ArbolBinario {
 private:
  struct Nodo {
    T data;
    Nodo* left;
    Nodo* right;
    // agregamos un parent para tener referencia al nodo anterior
    Nodo* parent;
    Nodo() {}
    Nodo(T data, Nodo* left = nullptr, Nodo* right = nullptr)
        : data(data), left(left), right(right) {}
  };
  Nodo* root;

  Nodo* crear_nodo(T value, Nodo* parent) {
    Nodo* nuevonodo = new Nodo(value);
    nuevonodo->parent = parent;
    return nuevonodo;
  }

  Nodo* insertarnodo(T value, Nodo*& nodo, Nodo* parent) {
    if (nodo == nullptr) {
      return crear_nodo(value, parent);
    } else if (value < nodo->data) {
      nodo->left = crear_nodo(value, nodo);
    } else if (value > nodo->data) {
      nodo->right = crear_nodo(value, nodo);
    } else {
      throw std::runtime_error(
          "Nodo existente");  // no manejar nodos duplicados
    }
    return nodo;
  }

  bool buscarnodo(T value, Nodo*& nodo) {
    Nodo* actual = nodo;
    while (actual != nullptr) {
      if (value < actual->data) {
        actual = actual->left;
      } else if (value > actual->data) {
        actual = actual->right;
      } else {
        // si el valor existe caerá aqui ya que no será ni menor ni mayor ni
        // nullptr, por eso return true
        return true;
      }
    }
    // en caso que en el bucle se haya llegado a un nullptr es porque el valor
    // estaba bajando y no existía, por eso sale del bucle y llega a esto
    return false;
  }

 public:
  ArbolBinario() {}
  ArbolBinario(Nodo* root = nullptr) : root(root) {}

  void insertar(T value) { root = insertarnodo(value, root, nullptr); }
  bool buscar(T value) { return buscarnodo(value, root); }
};

int main() { return 0; }