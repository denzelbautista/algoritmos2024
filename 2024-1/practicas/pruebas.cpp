#include <iostream>
using namespace std;
#include <bits/stdc++.h>

#include <array>
#include <set>
#include <vector>

void printSet(const std::set<int>& s) {
  for (const int& element : s) {
    std::cout << element << " ";
  }
  std::cout << std::endl;
}

int main() {
  vector<int> v3 = {1, 2, 3, 4};
  array<int, 10> v1 = {1};
  vector<int> v2 = {2, 4, 5, 8};
  /*
  v3.insert(v3.end() - 1, 10);
  for (const auto e : v1) {
    cout << e << " ";
  }
  */

  // set
  // Crear un set de enteros
  set<int> mySet;

  // Insertar elementos
  mySet.insert(10);
  mySet.insert(20);
  mySet.insert(30);
  mySet.insert(40);

  // Intentar insertar un elemento duplicado (no se insertará)
  mySet.insert(30);

  // Mostrar el contenido del set
  cout << "Elementos del set después de la inserción:" << endl;
  printSet(mySet);

  // Eliminar un elemento
  mySet.erase(20);
  cout << "Elementos del set después de eliminar 20:" << endl;
  printSet(mySet);

  // Reemplazar un elemento: Como no se puede reemplazar directamente,
  // eliminamos el elemento viejo y añadimos el nuevo.
  if (mySet.find(30) != mySet.end()) {
    mySet.erase(30);
    mySet.insert(35);
  }
  cout << "Elementos del set después de reemplazar 30 por 35:" << endl;
  printSet(mySet);

  // Iterar sobre los elementos del set
  cout << "Iterando sobre los elementos del set:" << endl;
  for (set<int>::iterator it = mySet.begin(); it != mySet.end(); ++it) {
    cout << *it << " ";
  }
  cout << endl;

  vector<int> va = {8, 2, 0, 9, 5, 3, 7, 1};

  sort(va.begin(), va.end(), { return a > b; });

  for (const auto& e : va) {
    cout << e << " ";
  }
  cout << endl;

  return 0;
}