#include <iostream>

void display(int arr[], int size) {
  for (size_t i = 0; i < size; i++)
    std::cout << arr[i] << " ";
  std::cout << std::endl;
}

void deleteElement(int arr[], int index, int &size) {
  if (index < 0 || index >= size || index == -1) {
    std::cout << "Cannot delete element from that index" << std::endl;
    return;
  }
  for (size_t i = index; i < size; i++) {
    arr[i] = arr[i + 1];
  }
  size--;
  std::cout << std::endl;
  display(arr, size);
}

int linearSearch(int arr[], int key, int size) {
  for (size_t i = 0; i < size; i++) {
    if (arr[i] == key)
      return i;
  }
  return -1;
}

int main() {

  std::cout << "Enter the size of the array;";
  int n;
  std::cin >> n;
  int *arr = new int[n];
  std::cout << "Enter the elements in the array" << std::endl;
  for (size_t i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  std::cout << "Original array :";
  for (size_t i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

  for (size_t i = 0; i < n; i++) {
    int key = arr[i];
    int index = linearSearch(arr + i, key, n - i);
    deleteElement(arr, index, n);
  }
  return 0;
}
