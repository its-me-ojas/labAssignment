// Write a program to find a saddle point in a two-dimensional array. A saddle
// point in a numerical array is a number that is larger than or equal to every
// number in its column, and smaller than or equal to every number in its row.
#include <iostream>

struct rowPair {
  int max;
  int index;
};

int rowColCheck(int arr[][3], struct rowPair obj) {
  for (size_t i = 0; i < 3; i++) {
    if (arr[obj.index][i] < obj.max)
      return -1;
  }
  return obj.max;
}

int main() {

  int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  struct rowPair obj;
  obj.max = 0;
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      if (arr[j][i] > obj.max) {
        obj.max = arr[j][i];
        obj.index = j;
      }
    }
    int check = rowColCheck(arr, obj);
    if (check != -1) {
      std::cout << "The number is : " << check << std::endl;
      return 0;
    }
  }

  return 0;
}
