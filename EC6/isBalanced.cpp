#include <cassert>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Integrantes:
- Josué Arbulú
- Denzel Bautista
- Rodrigo Lauz
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
  int balanceFactor(TreeNode* root) {
    TreeNode* temp = root;
    int left = 0, right = 0;

    while (temp->left != nullptr) {
      left++;
      temp = temp->left;
    }

    temp = root;

    while (temp->right != nullptr) {
      right++;
      temp = temp->right;
    }

    return left - right;
  }

  bool isBalanced(TreeNode* root) {
    bool balanced = true;
    if (balanceFactor(root) == 1 || balanceFactor(root) == -1 ||
        balanceFactor(root) == 0) {
      return balanced;
    } else {
      balanced = false;
      return balanced;
    }
  }
};

void test() {
  TreeNode* nodo_a = new TreeNode(3);
  TreeNode* nodo_b = new TreeNode(9);
  TreeNode* nodo_c = new TreeNode(20);
  TreeNode* nodo_d = new TreeNode(15);
  TreeNode* nodo_e = new TreeNode(7);

  nodo_a->left = nodo_b;
  nodo_a->right = nodo_c;
  nodo_c->left = nodo_d;
  nodo_c->right = nodo_e;
  assert(Solution().isBalanced(nodo_a) == true);

  nodo_a = new TreeNode(1);
  nodo_b = new TreeNode(2);
  nodo_c = new TreeNode(2);
  nodo_d = new TreeNode(3);
  nodo_e = new TreeNode(3);
  TreeNode* nodo_f = new TreeNode(4);
  TreeNode* nodo_g = new TreeNode(4);
  nodo_a->left = nodo_b;
  nodo_a->right = nodo_c;
  nodo_b->left = nodo_d;
  nodo_b->right = nodo_e;
  nodo_d->left = nodo_f;
  nodo_d->left = nodo_g;
  assert(Solution().isBalanced(nodo_a) == false);
}

int main() {
  test();
  return 0;
}
