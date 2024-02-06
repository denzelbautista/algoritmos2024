#include <iostream>
using namespace std;

struct TrieNode {
  TrieNode* children[26];
  char data;
  bool isLeaf;

  TrieNode(char ch) {
    data = ch;
    isLeaf = false;
    for (int i = 0; i < 26; i++) {
      children[i] = NULL;
    }
  }
};

class Trie {
 public:
  // to implement trie we need to ready our TrieNode
  TrieNode* root;
  Trie() {
    // make the root node
    root = new TrieNode('\0');  // null terminator
  }

  void insert(string word) { insertUtil(root, word); }

  bool search(string word) { return searchUtil(root, word); }

  bool startsWith(string prefix) { return startWithUtil(root, prefix); }

  // FUNTIONS

  bool startWithUtil(TrieNode* root, string word) {
    // base case
    if (word.length() == 0) {
      // we reached to end of prefix then return true;
      return true;
    }

    int index = word[0] - 'a';

    if (root->children[index] != NULL) {
      // go for searching ahead
      return startWithUtil(root->children[index], word.substr(1));
    }

    return false;  // becase we could not find the alphabet
  }

  bool searchUtil(TrieNode* root, string word) {
    // base case
    if (word.length() == 0) {
      // check if word end is a terminal node or node
      return root->isLeaf;
    }

    int index = word[0] - 'a';

    if (root->children[index] != NULL) {
      // go for searching ahead
      return searchUtil(root->children[index], word.substr(1));
    }

    return false;  // becase we could not find the alphabet
  }

  void insertUtil(TrieNode* root, string word) {
    // base case
    if (word.length() == 0) {
      // make the node as terminal node
      root->isLeaf = true;
      return;
    }

    // get the index as we have only lowercase letters
    int index = word[0] - 'a';
    TrieNode* nextNode;

    // if root with character word[0] alredy exist
    if (root->children[index] != NULL) {
      nextNode = root->children[index];
    }

    // if don't exist
    else {
      root->children[index] =
          new TrieNode(word[0]);  // make a new node and put at this place
      nextNode = root->children[index];

      // OR
      //  child=new TrieNode(word[0]);
      //  root->children[index]=child;
    }

    // go for recursive call
    insertUtil(
        nextNode,
        word.substr(1));  // substr will pass the string except the first letter
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
  Trie* tri = new Trie();
  tri->insert("hola");
  cout << boolalpha << tri->search("hola") << endl;

  cout << boolalpha << tri->startsWith("hol") << endl;
  cout << boolalpha << tri->startsWith("he") << endl;
  tri->insert("hello");
  cout << boolalpha << tri->startsWith("he") << endl;
  int index = 'h' - 'a';
  cout << index << endl;

  return 0;
}