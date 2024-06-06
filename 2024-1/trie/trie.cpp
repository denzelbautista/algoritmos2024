#include <iostream>
using namespace std;

struct TrieNode {
  TrieNode* children[27];
  bool endWord;
  int count;
}

bool search(TrieNode* nodo, string key){
  for (int i = 0; i < key.size(), i++) {
    if (nodo->children[key[i] - 'a'] != nullptr) {
      nodo = nodo->children[key[i]];
    }
  }
}