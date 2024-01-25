#include <cassert>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// Integrantes
/*
Rodrigo Lauz
Josue Arbulu
Denzel Bautista
*/

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
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1 == nullptr) {
      return t2;
    }
    if (t2 == nullptr) {
      return t1;
    }
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);
    return t1;
  }

  TreeNode* canMerge(vector<TreeNode*>& trees) {
    unordered_map<int, TreeNode*> roots;
    for (auto tree : trees) {
      roots[tree->val] = tree;
    }
    TreeNode* root = nullptr;
    for (auto tree : trees) {
      if (roots.find(tree->val) != roots.end()) {
        if (tree->left != nullptr) {
          roots.erase(tree->left->val);
        }
        if (tree->right != nullptr) {
          roots.erase(tree->right->val);
        }
        roots.erase(tree->val);
        if (root == nullptr) {
          root = tree;
        } else {
          root = mergeTrees(root, tree);
        }
      }
    }
    return root;
  }
};

void test() {
  TreeNode* nodo_a = new TreeNode(2);
  TreeNode* nodo_b = new TreeNode(1);

  TreeNode* nodo_c = new TreeNode(3);
  TreeNode* nodo_d = new TreeNode(2);
  TreeNode* nodo_e = new TreeNode(5);

  TreeNode* nodo_f = new TreeNode(5);
  TreeNode* nodo_g = new TreeNode(4);

  nodo_a->left = nodo_b;

  nodo_c->left = nodo_d;
  nodo_c->right = nodo_e;

  nodo_f->left = nodo_g;

  vector<TreeNode*> trees = {nodo_c, nodo_f};

  TreeNode* ans = Solution().canMerge(trees);
  assert(ans == nodo_c);
}

int main() {
  test();
  return 0;
}