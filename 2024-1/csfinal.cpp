#include <iostream>
using namespace std;

int* countingsort(int arr[], int size) {
  int count[10] = {0};
  int* result = new int[size];
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < 10; j++) {
      if (arr[i] == j) {
        count[j]++;
      }
    }
  }

  for (int j = 0; j < 9; j++) {
    count[j + 1] += count[j];
  }

  for (int i = size - 1; i >= 0; i--) {
    result[count[arr[i]] - 1] = arr[i];
    count[arr[i]]--;
  }

  return result;
}

void imprimir(const int arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i];
    if (i < size - 1) {
      cout << ", ";
    }
  }
  cout << endl;
}

int main() {
  int prueba[7] = {1, 4, 1, 2, 7, 5, 2};
  int* res = countingsort(prueba, 7);
  imprimir(res, 7);

  delete[] res;

  return 0;
}
