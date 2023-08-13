// Write a program to count the total number of distinct elements in an array of
// length n.

#include <iostream>
#include <unordered_set>

int distinctElements(int arr[], int size) {
  // we will be using unordered_set because it can store distinct values even if
  // we add multiple duplicate values
  std::unordered_set<int> distinct;
  for (size_t i = 0; i < size; i++) {
    distinct.insert(arr[i]);
  }
  return distinct.size();
}

// int distinctElements(int arr[], int n) {
//   int distinctCount = 0;

//   for (int i = 0; i < n; ++i) {
//     bool isDistinct = true;
//     for (int j = 0; j < i; ++j) {
//       if (arr[i] == arr[j]) {
//         isDistinct = false;
//         break;
//       }
//     }
//     if (isDistinct) {
//       distinctCount++;
//     }
//   }

//   return distinctCount;
// }

int main() {

  int arr[] = {1, 1, 1, 1, 2, 4, 5, 5, 6, 6, 3, 3, 8, 9, 7, 7};
  int size = sizeof(arr) / sizeof(int);

  std::cout << distinctElements(arr, size) << " distinct elements are present"
            << std::endl;

  return 0;
}
