#include <iostream>
using namespace std;

int countingsort(int arr[], int size) {
  int count[10] = {0};
  int result[size] = {0};
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
  for (int i = 0; i < size; i++) {
    result[count[arr[i] - 1]] = arr[i];
    count[arr[i]]--;
  }

  return result[size];
}

void imprimir(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << ", ";
  }
}

int main() {
  int prueba[7] = {1, 4, 1, 2, 7, 5, 2};
  int res[7] = {0};
  res[7] = countingsort(prueba, 7);
  imprimir(res, 7);

  return 0;
}