#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()
#include <iostream>

using namespace std;

void countingSort(int arr[], int n, int exp) {
  int output[n];
  int count[10] = {0};

  for (int i = 0; i < n; i++) {
    count[(arr[i] / exp) % 10]++;
  }

  for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  for (int i = n - 1; i >= 0; i--) {
    output[count[(arr[i] / exp) % 10] - 1] = arr[i];
    count[(arr[i] / exp) % 10]--;
  }

  for (int i = 0; i < n; i++) {
    arr[i] = output[i];
  }
}

void radixSort(int arr[], int n) {
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  for (int exp = 1; max / exp > 0; exp *= 10) {
    countingSort(arr, n, exp);
  }
}

// Función para generar un array de tamaño 'size' con números aleatorios entre 0
// y 999999
void generateRandomArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % 1000000;
  }
}

int main() {
  srand(time(0));  // Inicializar la semilla para generar números aleatorios

  int sizes[] = {100, 1000, 10000};
  int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

  for (int i = 0; i < num_sizes; i++) {
    int size = sizes[i];
    int *arr = new int[size];

    generateRandomArray(arr, size);

    clock_t start = clock();  // Marcar el tiempo de inicio
    radixSort(arr, size);
    clock_t end = clock();  // Marcar el tiempo de finalización

    double elapsed_secs = double(end - start) /
                          CLOCKS_PER_SEC;  // Calcular el tiempo transcurrido

    cout << "Tiempo para ordenar un array de tamaño " << size << ": "
         << elapsed_secs << " segundos" << endl;

    delete[] arr;  // Liberar la memoria del array
  }

  return 0;
}