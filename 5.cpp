// Write a program to find sum of every row and every column in a
// two-dimensional array.

#include <iostream>
struct Sum {
  int rowSum, colSum;
};

int main() {

  int rows, cols;
  struct Sum sum;
  std::cout << "Enter the rows and cols: ";

  // allocating memory for the arrays
  int **arr = new int *[rows];
  for (size_t i = 0; i < cols; i++) {
    arr[i] = new int[cols];
  }

  std::cout << "Enter the elements" << std::endl;
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      std::cin >> arr[i][j];

    }
  }
  return 0;
}
