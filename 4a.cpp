// Reverse the elements of an array

#include <fstream>
#include <iostream>

// passinf as pointer is the same thing as passing as int arr[] as arr is just a
// pointer to the start
void reverseArray(int *ptr, int size) {
  int start = 0;
  int end = size - 1;
  // we are using two pointer method in which one pointer starts from the start
  // and the other from the end in each iteration the start position element and
  // the end postion element gets swapped
  while (start < end) {
    // the swap can be done using the inbuilt function or you can just use th
    // temp varaible method
    std::swap((ptr[start]), (ptr[end]));
    start++;
    end--;
  }
}

int main() {
  int arr[] = {1, 3, 5, 7, 9, 2, 4, 6, 8};
  // way to find the size of the given array
  int size = sizeof(arr) / sizeof(int);

  std::cout << "Original Array: ";
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  reverseArray(arr, size);

  std::cout << "Reversed Array: ";
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
