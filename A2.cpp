// Given a matrix of M * N elements (M rows, N columns), return all elements of
// the matrix in spiral order.
#include <iostream>

void spiralMatrix(int arr[][3], int row, int col) {
  int rowStart = 0, rowEnd = row - 1;
  int colStart = 0, colEnd = col - 1;
  while (rowStart <= rowEnd && colStart <= colEnd) {
    // first row
    for (int i = colStart; i <= colEnd; i++) {
      std::cout << arr[rowStart][i] << " ";
    }
    rowStart++;

    // end col
    for (int i = rowStart; i <= rowEnd; i++) {
      std::cout << arr[i][colEnd] << " ";
    }
    colEnd--;

    // bottom row
    for (int i = colEnd; i >= colStart; i--) {
      std::cout << arr[rowEnd][i] << " ";
    }
    rowEnd--;

    // start col
    for (int i = rowEnd; i >= rowStart; i--) {
      std::cout << arr[i][colStart] << " ";
    }
    colStart++;
  }
}

int main() {
  int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  spiralMatrix(arr, 3, 3);

  return 0;
}
