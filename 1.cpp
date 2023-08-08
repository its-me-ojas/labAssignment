#include <iomanip>
#include <iostream>

bool binarySearch(int arr[], int size, int key) {
  int start = 0, end = size - 1;
  int mid = start + (end - start) / 2;

  while (start <= end) {
    if (arr[mid] > key) {
      end = mid - 1;
    } else if (arr[mid] < key) {
      start = mid + 1;
    } else
      return true;
    mid = start + (end - start) / 2;
  }
  return false;
}

int main() {

  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int size = sizeof(arr) / sizeof(int);
  int key;
  std::cout << "Enter the key to search" << std::endl;
  std::cin >> key;

  std::cout << std::boolalpha
            << "Is key present? : " << binarySearch(arr, size, key)
            << std::endl;

  return 0;
}
