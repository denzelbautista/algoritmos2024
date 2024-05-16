#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class BSTree {
  struct NodeBT {
    T data;
    NodeBT *left;
    NodeBT *right;

    NodeBT(T _data) {
      data = _data;
      left = nullptr;
      right = nullptr;
    }
  };

  NodeBT *root;

  BSTree() {}

  bool find(NodeBT *node, T value) {
    if (node == nullptr) {
      return false;
    } else if (value < node->data) {
      return find(node->left, value);
    } else if (value > node->data) {
      return find(node->right, value);
    } else
      return true;
  }

  void inorder_it(NodeBT *node) {
    stack<NodeBT *> st;
    NodeBT *current = node;
    while (current != nullptr || !st.empty()) {
      while (current != null) {
        st.push(current);
        current = current->left;
      }
      current = st.top();
      st.pop();
      cout << current->data << " ";
      current = current->right;
    }
  }

  void inorder_rec(NodeBT *node) {
    if (node == NULL) {
      return;
    }
    inorder_rec(node->left);
    cout << node->data << " ";
    inorder_rec(node->right);
  }

  void insert(T data) {
    NodeBT<T> *nuevo = new NodeBT<T>(data);
    if (root == nullptr) {
      root = nuevo;
    } else {
      NodeBT<T> *current = root;
      while (current != nullptr) {
        if (data < current->data) {
          if (current->left == nullptr) {
            current->left = nuevo;
            break;
          } else {
            current = current->left;
          }
        } else if (data > current->data) {
          if (current->right == nullptr) {
            current->right = nuevo;
            break;
          } else {
            current = current->right;
          }
        } else {
          break;
        }
      }
    }
  }
};
/*
     if (data < root->data) {
        while (current->left != nullptr) {
          current = current->left;
        }
        current->left = nuevo;
      } else {
        while (current->right != nullptr) {
          current = current->left;
        }
        current->left = nuevo;
      }

*/

int main() { return 0; }