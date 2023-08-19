// Given an integer A, generate a square matrix filled with elements from 1 to
// A2 in spiral order and return the generated square matrix.

// Approach :
// a) first inialise a 2d array with like this array[n][n] where n is the given
// number b) then we will traverse the array like we do in spiral matrix and use
// a counter variable to initialise elements in the array
// c) counter will be updated after each assignment

#include <iostream>

void spiralAssignment(int **arr, int size) {
  int rowStart = 0, colStart = 0;
  int rowEnd = size - 1, colEnd = size - 1;
  int counter = 1;
  while (rowStart <= rowEnd && colStart <= colEnd) {
    // first row
    for (int i = colStart; i <= colEnd; i++) {
      arr[rowStart][i] = counter;
      counter++;
    }
    rowStart++;

    // end col
    for (int i = rowStart; i <= rowEnd; i++) {
      arr[i][colEnd] = counter;
      counter++;
    }
    colEnd--;

    // bottom row
    for (int i = colEnd; i >= colStart; i--) {
      arr[rowEnd][i] = counter;
      counter++;
    }
    rowEnd--;

    // start col
    for (int i = rowEnd; i >= rowStart; i--) {
      arr[i][colStart] = counter;
      counter++;
    }
    colStart++;
  }
}

void printSpiralMatrix(int **arr, int row, int col) {
  for (size_t i = 0; i < row; i++) {
    for (size_t j = 0; j < col; j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
int main() {
  std::cout << "Enter the number : ";
  int n;
  std::cin >> n;

  // initialising 2d array
  int **arr = new int *[n];
  for (size_t i = 0; i < n; i++) {
    arr[i] = new int[n];
  }

  spiralAssignment(arr, n);
  printSpiralMatrix(arr, n, n);
  return 0;
}
