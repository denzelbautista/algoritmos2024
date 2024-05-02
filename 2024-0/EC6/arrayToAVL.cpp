#include <algorithm>
#include <cassert>
#include <cmath>
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
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode *arrayToAVL(vector<int> &array) {
    // add your code
    /*
    El algoritmo seria el siguiente:
    - Se ordena el array
    - Se encuentra el termino medio del array
    - Se separa el lado derecho e izquierdo y se les encuentra el termino medio
    a esos sub arrays derecho e izquierdo.
    - Los terminos medios de esos primeros subarrays L y R serían los dos
    primeros hijos del nodo raiz.
    - Este algoritmo se aplica recursivamente hasta crear el arbol.
    */
    sort(array.begin(), array.end());
    int n = array.size();
    if (n == 0) return nullptr;  // Base case: empty array
    int mid = n / 2;
    TreeNode *root = new TreeNode(array[mid]);
    if (n == 1) return root;
    vector<int> left(array.begin(), array.begin() + mid);
    vector<int> right(array.begin() + mid + 1, array.end());
    root->left = arrayToAVL(left);
    root->right = arrayToAVL(right);
    return root;
  }
};

vector<int> levelOrder(TreeNode *root) {
  vector<int> vec;
  if (root == NULL) return vec;

  queue<TreeNode *> q;
  q.push(root);

  while (q.empty() == false) {
    TreeNode *node = q.front();
    vec.push_back(node->val);
    q.pop();
    if (node->left != NULL) q.push(node->left);
    if (node->right != NULL) q.push(node->right);
  }
  return vec;
}

void test() {
  vector<int> array = {2, 4, 1, 3, 5, 6, 7};
  vector<int> expected = {4, 2, 6, 1, 3, 5, 7};
  vector<int> ans = levelOrder(Solution().arrayToAVL(array));
  assert(ans == expected);

  array = {8, 10, 15, 25, 49, 56, 60, 64, 75, 89, 100};
  expected = {56, 15, 75, 8, 25, 60, 89, 10, 49, 64, 100};
  ans = levelOrder(Solution().arrayToAVL(array));
  cout << "ans: ";
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  cout << endl;
  cout << "expected: ";
  for (int i = 0; i < expected.size(); i++) cout << expected[i] << " ";
  cout << endl;
  assert(ans == expected);
}

int main() {
  test();
  return 0;
}