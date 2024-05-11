#include <iostream>
#include <string>
#include <vector>
// Para hash table usamos la libreria unordered_map
#include <unordered_map>
using namespace std;

/*
void insert(key,value){
    int hashcode = gethashcode(key);
    int index = hashcode % capacity

    array[index].push_front(key);
    }

*/

int fhash(string tohash) {
  int hash = 0;
  for (auto character : tohash) {
    hash += int(character);
  }
  return hash;
}

int main() {
  // string d = "tac";
  // cout << fhash(d) << endl;
  unordered_map<string, int> notas;  // creando un hash table
  // insertando elementos
  notas["Martin"] = 15;
  notas["Julia"] = 18;
  notas["Pepe"] = 19;
  notas["Marta"] = 11;
  // contar los buckets del unordered
  cout << "Tamaño del array: " << notas.bucket_count() << endl;
  // recorrer los elemntos del unordered (hash)
  for (const auto& pair : notas) {
    cout << pair.first << " : " << pair.second << endl;
  }

  // ahora recorrer bucket por bucker y ver que elementos tiene c/u
  for (int i = 0; i < notas.bucket_count(); i++) {
    cout << "Bucket " << i << " = ";
    for (auto it = notas.begin(i); it != notas.end(i); it++) {
      cout << (*it).first << " : " << (*it).second << ", ";
    }
    cout << endl;
  }
  return 0;
}

/*
hashTable h1;
h1.set("clave", valor);
*/