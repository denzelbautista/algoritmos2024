#include <cassert>
#include <cmath>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

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
  void insertNode(TreeNode* node, vector<TreeNode*>& vec) {
    if (node != nullptr) {
      insertNode(node->left, vec);
      vec.push_back(node);
      insertNode(node->right, vec);
    }
  }

  TreeNode* arrayToAVL(vector<TreeNode*>& array) {
    int n = array.size();
    if (n == 0) return nullptr;  // Base case: empty array
    int mid = n / 2;
    TreeNode* root = array[mid];
    if (n == 1) return root;
    vector<TreeNode*> left(array.begin(), array.begin() + mid);
    vector<TreeNode*> right(array.begin() + mid + 1, array.end());
    root->left = arrayToAVL(left);
    root->right = arrayToAVL(right);
    return root;
  }
  TreeNode* balanceBST(TreeNode* root) {
    vector<TreeNode*> nodes;

    insertNode(root, nodes);

    return arrayToAVL(nodes);
  }
};

void test() {
  TreeNode* nodo_a = new TreeNode(1);
  TreeNode* nodo_b = new TreeNode(2);
  TreeNode* nodo_c = new TreeNode(3);
  TreeNode* nodo_d = new TreeNode(4);
  nodo_a->right = nodo_b;
  nodo_b->right = nodo_c;
  nodo_c->right = nodo_d;
  assert(Solution().balanceBST(nodo_a) == nodo_c);

  nodo_a = new TreeNode(2);
  nodo_b = new TreeNode(1);
  nodo_c = new TreeNode(3);
  nodo_a->left = nodo_b;
  nodo_a->right = nodo_c;
  assert(Solution().balanceBST(nodo_a) == nodo_a);
}

int main() {
  test();
  return 0;
}