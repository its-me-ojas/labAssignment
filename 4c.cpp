// Find the Transpose of a Matrix

#include <iostream>
int main() {

  int rows, cols;
  std::cout << "Enter the rows and cols";
  std::cin >> rows >> cols;

  // break case
  if (rows != cols) {
    std::cout << "Square matrix needed";
    return 0;
  }
  // allocating memory for the arrays
  int **arr = new int *[rows];
  int **trans = new int *[rows];
  for (size_t i = 0; i < cols; i++) {
    arr[i] = new int[cols];
  }
  for (size_t i = 0; i < cols; i++) {
    trans[i] = new int[cols];
  }

  // initialising the arrays
  std::cout << "Enter the elements" << std::endl;
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      std::cin >> arr[i][j];
    }
  }

  // printing the array
  std::cout << "Original" << std::endl;
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << std::endl;
  }

  // tranposing
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      trans[j][i] = arr[i][j];
    }
  }

  // printing the array
  std::cout << "Transpose" << std::endl;
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      std::cout << trans[i][j] << " ";
    }
    std::cout << std::endl;
  }
  // Free the dynamically allocated memory
  for (size_t i = 0; i < rows; i++) {
    delete[] arr[i];
  }
  delete[] arr;

  for (size_t i = 0; i < rows; i++) {
    delete[] trans[i];
  }
  delete[] trans;

  return 0;
}
