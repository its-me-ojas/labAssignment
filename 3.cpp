// Design the Logic to Find a Missing Number in a Sorted Array
#include <iostream>

int missingNumber(int arr[], int size) {
  int start = 0, end = size - 1;
  int mid = start + (end - start) / 2;
  while (start <= end) {
    if (arr[mid] - mid != 1)
      end = mid - 1;
    else
      start = mid + 1;
    mid = start + (end - start) / 2;
  }
  return arr[start] - 1;
}

int main() {
  int arr[] = {1, 2, 3, 4, 6, 7, 8, 9, 10};
  int size = sizeof(arr) / sizeof(int);

  std::cout << missingNumber(arr, size) << std::endl;

  return 0;
}
