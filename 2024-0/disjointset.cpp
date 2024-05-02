#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct Node {
  T data;
  Node<T> *parent = nullptr;
  Node() {}
  Node(T t) { data = t; }
};

template <typename T>
class DisjointSet {
 public:
  void makeSet(Node<T> *x) { x->parent = x; }

  Node<T> *find(Node<T> *x) {
    if (x == x->parent) {
      return x;
    } else {
      return find(x->parent);
    }
  }

  void setUnion(Node<T> *x, Node<T> *y) {
    Node<T> *xRoot = find(x);
    Node<T> *yRoot = find(y);
    xRoot->parent = yRoot;
  }
};

void solveIslands(vector<vector<int>> &grid) {
  int n = grid.size();
  int m = grid[0].size();
  DisjointSet<int> ds;
  vector<vector<Node<int> *>> nodeGrid(n, vector<Node<int> *>(m, nullptr));

  // Paso 1: Crear nodos y conjuntos disjuntos
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == 1) {
        nodeGrid[i][j] = new Node<int>(1);
        ds.makeSet(nodeGrid[i][j]);
      }
    }
  }

  // Paso 2: Unir nodos vecinos
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == 1) {
        if (i > 0 && grid[i - 1][j] == 1)
          ds.setUnion(nodeGrid[i][j], nodeGrid[i - 1][j]);
        if (j > 0 && grid[i][j - 1] == 1)
          ds.setUnion(nodeGrid[i][j], nodeGrid[i][j - 1]);
      }
    }
  }

  // Paso 3: Contar islas únicas
  int numberOfIslands = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (nodeGrid[i][j] != nullptr &&
          ds.find(nodeGrid[i][j]) == nodeGrid[i][j]) {
        numberOfIslands++;
      }
    }
  }

  // Libera memoria si es necesario
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (nodeGrid[i][j] != nullptr) {
        delete nodeGrid[i][j];
      }
    }
  }

  cout << "Número de islas: " << numberOfIslands << endl;
}

int main() {
  vector<vector<int>> grid = {
      {1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 1, 1}};
  solveIslands(grid);
  return 0;
}