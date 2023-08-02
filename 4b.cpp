// Find the matrix multiplication

#include <iostream>
int main() {
  // get the number of rows and columns from the user
  int rows1, rows2, cols1, cols2;
  std::cout << "Enter the rows and cols for first matrix: ";
  std::cin >> rows1 >> cols1;
  std::cout << std::endl;
  std::cout << "Enter the rows and cols for second matrix: ";
  std::cin >> rows2 >> cols2;

  // break case
  if (cols1 != rows2) {
    return 0;
  }

  // allocating memory for the arrays
  int **arr1 = new int *[rows1];
  int **arr2 = new int *[rows2];
  int **arr3 = new int *[rows1];
  for (size_t i = 0; i < cols1; i++) {
    arr1[i] = new int[cols1];
  }
  for (size_t i = 0; i < cols2; i++) {
    arr2[i] = new int[cols2];
  }
  for (size_t i = 0; i < cols2; i++) {
    arr3[i] = new int[cols2];
  }

  // initialising the arrays
  std::cout << "For array 1" << std::endl;
  for (size_t i = 0; i < rows1; i++) {
    for (size_t j = 0; j < cols1; j++) {
      std::cin >> arr1[i][j];
    }
  }
  std::cout << std::endl;
  std::cout << "For array 2" << std::endl;
  for (size_t i = 0; i < rows2; i++) {
    for (size_t j = 0; j < cols2; j++) {
      std::cin >> arr2[i][j];
    }
  }

  // printing the arrays
  std::cout << "Array 1" << std::endl;
  for (size_t i = 0; i < rows1; i++) {
    for (size_t j = 0; j < cols1; j++) {
      std::cout << arr1[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  std::cout << "Array 2" << std::endl;
  for (size_t i = 0; i < rows2; i++) {
    for (size_t j = 0; j < cols2; j++) {
      std::cout << arr2[i][j] << " ";
    }
    std::cout << std::endl;
  }

  for (size_t i = 0; i < rows1; i++) {
    for (size_t j = 0; j < cols2; j++) {
      int sum = 0;
      for (size_t k = 0; k < cols1; k++) {
        sum += (arr1[i][k] * arr2[k][j]);
      }
      arr3[i][j] = sum;
    }
  }
  // printing the result
  std::cout << "Array 1X2" << std::endl;
  for (size_t i = 0; i < rows1; i++) {
    for (size_t j = 0; j < cols2; j++) {
      std::cout << arr3[i][j] << " ";
    }
    std::cout << std::endl;
  }

  // Free the dynamically allocated memory
  for (size_t i = 0; i < rows1; i++) {
    delete[] arr1[i];
  }
  delete[] arr1;

  for (size_t i = 0; i < rows2; i++) {
    delete[] arr2[i];
  }
  delete[] arr2;

  for (size_t i = 0; i < rows1; i++) {
    delete[] arr3[i];
  }
  delete[] arr3;
  return 0;
}
