#include <fstream>
#include <iostream>

void bubbleSort(int arr[], int size) {

  for (size_t i = 0; i < size - 1; i++) {
    for (size_t j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }
}

void printArray(int arr[], int size) {
  for (size_t i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}
int main() {

  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int size = sizeof(arr) / sizeof(int);

  printArray(arr, size);
  bubbleSort(arr, size);
  printArray(arr, size);

  return 0;
}
