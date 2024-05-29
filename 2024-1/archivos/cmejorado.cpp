#include <iostream>

void countingsort(int arr[], int size) {
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

  for (int i = size - 1; i >= 0; i--) {
    result[count[arr[i]] - 1] = arr[i];
    count[arr[i]]--;
  }

  // Copiamos los valores ordenados de result a arr
  for (int i = 0; i < size; i++) {
    arr[i] = result[i];
  }
}

void imprimir(const int arr[], int size) {
  for (int i = 0; i < size; i++) {
    std::cout << arr[i];
    if (i < size - 1) {
      std::cout << ", ";
    }
  }
  std::cout << std::endl;
}

int main() {
  int prueba[7] = {1, 4, 1, 2, 7, 5, 2};
  countingsort(prueba, 7);
  imprimir(prueba, 7);

  return 0;
}
