// Let A[1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said to
// be an inversion if these numbers are out of order, i.e., i < j but A[i]>A[j
// ]. Write a program to count the number of inversions in an array.

#include <iostream>
int main() {
  int inv = 0;
  int arr[] = {3, 2, 4, 1, 5};
  int size = sizeof(arr) / sizeof(int);
  for (size_t i = 0; i < size; i++) {
    for (size_t j = i + 1; j < size; j++) {
      if (arr[i] > arr[j])
        inv++;
    }
  }
  std::cout << inv << std::endl;
  return 0;
}
