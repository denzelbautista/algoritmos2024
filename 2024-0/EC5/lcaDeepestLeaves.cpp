#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Integrantes
/*
Rodrigo Lauz
Josue Arbulu
Denzel Bautista
*/

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// Find function
bool contains(int value, TreeNode* root) {
  if (root == nullptr) {
    return false;
  }
  queue<TreeNode*> q;
  q.push(root);
  while (q.empty() == false) {
    if (q.front()->val == value) {
      return true;
    }
    if (q.front()->left != nullptr) {
      q.push(q.front()->left);
    }
    if (q.front()->right != nullptr) {
      q.push(q.front()->right);
    }
    q.pop();
  }
  return false;
}

class Solution {
 public:
  TreeNode* lcaDeepestLeaves(TreeNode* root) {
    // add your code
    vector<TreeNode*> current = {}, next = {root};

    // Travel to deepest level
    while (!next.empty()) {
      current = next;
      next = {};

      for (int i = 0; i < current.size(); i++) {
        if (current[i]->left != nullptr) {
          next.push_back(current[i]->left);
        }
        if (current[i]->right != nullptr) {
          next.push_back(current[i]->right);
        }
      }
    }

    // Find deepest common parent by searching all deepest nodes on the current
    // parent's childs
    TreeNode* temp = root;
    bool found = true;
    while (found == true) {
      found = true;
      for (int i = 0; i < current.size(); i++) {
        if (contains(current[i]->val, temp->left) == false) {
          found = false;
          break;
        }
      }

      if (found) {
        temp = temp->left;
      }

      else {
        found = true;
        for (int i = 0; i < current.size(); i++) {
          if (contains(current[i]->val, temp->right) == false) {
            found = false;
            break;
          }
        }

        if (found) {
          temp = temp->right;
        }
      }
    }
    return temp;
  }
};

void test() {
  TreeNode* nodo_a = new TreeNode(3);
  TreeNode* nodo_b = new TreeNode(5);
  TreeNode* nodo_c = new TreeNode(1);
  TreeNode* nodo_d = new TreeNode(6);
  TreeNode* nodo_e = new TreeNode(2);
  TreeNode* nodo_f = new TreeNode(0);
  TreeNode* nodo_g = new TreeNode(8);
  TreeNode* nodo_h = new TreeNode(7);
  TreeNode* nodo_i = new TreeNode(4);
  nodo_a->left = nodo_b;
  nodo_a->right = nodo_c;
  nodo_b->left = nodo_d;
  nodo_b->right = nodo_e;
  nodo_c->left = nodo_f;
  nodo_c->right = nodo_g;
  nodo_e->left = nodo_h;
  nodo_e->right = nodo_i;
  assert(Solution().lcaDeepestLeaves(nodo_a) == nodo_e);

  nodo_a = new TreeNode(0);
  nodo_b = new TreeNode(1);
  nodo_c = new TreeNode(3);
  nodo_d = new TreeNode(2);
  nodo_a->left = nodo_b;
  nodo_a->right = nodo_c;
  nodo_b->right = nodo_d;
  assert(Solution().lcaDeepestLeaves(nodo_a) == nodo_d);
}

int main() {
  test();
  return 0;
}