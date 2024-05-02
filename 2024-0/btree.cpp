#include <iostream>
#include <vector>

struct BTreeNode {
  std::vector<int> keys;
  std::vector<BTreeNode *> children;
  bool leaf;
};

class BTree {
 private:
  BTreeNode *root;
  int t;  // Minimo grado

  void splitChild(BTreeNode *x, int i) {
    BTreeNode *y = x->children[i];  // 'y' es el nodo to be split
    BTreeNode *z = new BTreeNode;   // 'z' es el new node despues del split
    z->leaf = y->leaf;              // Copy 'leaf' property de 'y' a 'z'
    x->children.insert(x->children.begin() + i + 1,
                       z);  // Insert 'z' en children de 'x'
    x->keys.insert(x->keys.begin() + i,
                   y->keys[t - 1]);  // Move key from 'y' a 'x'
    z->keys.assign(y->keys.begin() + t,
                   y->keys.end());  // Move remaining keys de 'y' a 'z'
    y->keys.erase(y->keys.begin() + t - 1,
                  y->keys.end());  // Erase moved keys de 'y'
    if (!y->leaf) {  // If 'y' no es leaf, move children de 'y' a 'z', and erase
                     // moved children de 'y'
      z->children.assign(y->children.begin() + t, y->children.end());
      y->children.erase(y->children.begin() + t, y->children.end());
    }
  }

  void insertNonFull(BTreeNode *x, int k) {
    int i = x->keys.size() - 1;
    if (x->leaf) {
      x->keys.insert(x->keys.begin() + i + 1, k);
    } else {
      while (i >= 0 && k < x->keys[i]) {
        i--;
      }
      i++;
      if (x->children[i]->keys.size() == (2 * t - 1)) {
        splitChild(x, i);
        if (k > x->keys[i]) {
          i++;
        }
      }
      insertNonFull(x->children[i], k);
    }
  }

  BTreeNode *searchHelper(BTreeNode *x, int k) {
    int i = 0;
    while (i < x->keys.size() && k > x->keys[i]) {
      i++;
    }
    if (i < x->keys.size() && k == x->keys[i]) {
      return x;
    } else if (x->leaf) {
      return nullptr;
    } else {
      return searchHelper(x->children[i], k);
    }
  }

  ///////////////////////////
 public:
  BTree(int _t) {
    root = nullptr;
    t = _t;  // Asignar el minimo grado del btree
  }

  void insert(int k) {
    if (root == nullptr) {
      root = new BTreeNode;
      root->keys.push_back(k);
      root->leaf = true;
    } else {
      if (root->keys.size() == (2 * t - 1)) {
        BTreeNode *s = new BTreeNode;
        s->children.push_back(root);
        splitChild(s, 0);
        root = s;
      }
      insertNonFull(root, k);
    }
  }

  BTreeNode *search(int k) {
    return (root == nullptr) ? nullptr : searchHelper(root, k);
  }
};

int main() {
  // Crear un BTree con t=3
  BTree bTree(3);

  // Insertar algunos valores
  bTree.insert(10);
  bTree.insert(20);
  bTree.insert(30);
  bTree.insert(40);
  bTree.insert(50);

  // Buscar algunos valores
  if (bTree.search(20) != nullptr) {
    std::cout << "Found 20 in the BTree" << std::endl;
  } else {
    std::cout << "Did not find 20 in the BTree" << std::endl;
  }

  if (bTree.search(60) != nullptr) {
    std::cout << "Found 60 in the BTree" << std::endl;
  } else {
    std::cout << "Did not find 60 in the BTree" << std::endl;
  }

  return 0;
}