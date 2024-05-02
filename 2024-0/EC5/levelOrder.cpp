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

/* Definition for a binary tree node. */
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> orden;
    queue<TreeNode*> cola;
    if (root == NULL) {
      orden.push_back({{}});
    }
    cola.push(root);
    vector<int> temp;
    TreeNode* tempr = root;
    while (!cola.empty()) {
      temp.push_back(cola.front()->val);

      cola.pop();
      while (!cola.empty()) {
        temp.push_back(cola.front()->val);
        root = cola.front();
        cola.pop();
      }

      if (cola.empty()) {
        if (root->left != nullptr) {
          cola.push(root->left);
        }
        if (root->right != nullptr) {
          cola.push(root->right);
        }
      }

      orden.push_back(temp);
      temp = {};
    }
    return orden;
  }
};

void test() {
  vector<vector<int>> ans = {{3}, {9, 20}, {15, 7}};
  TreeNode* nodo_a = new TreeNode(3);
  TreeNode* nodo_b = new TreeNode(9);
  TreeNode* nodo_c = new TreeNode(20);
  TreeNode* nodo_d = new TreeNode(15);
  TreeNode* nodo_e = new TreeNode(7);
  nodo_a->left = nodo_b;
  nodo_a->right = nodo_c;
  nodo_c->left = nodo_d;
  nodo_c->right = nodo_e;

  assert(Solution().levelOrder(nodo_a) == ans);
  ans = {{1}};
  nodo_a = new TreeNode(1);
  assert(Solution().levelOrder(nodo_a) == ans);
}

int main() {
  test();
  return 0;
}
