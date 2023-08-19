// // Write a program to implement the following operations on a Sparse Matrix,
// assuming the matrix is represented using a triplet.
// (a) Transpose of a matrix.
// (b) Addition of two matrices.
// (c) Multiplication of two matrices.

#include <iostream>
#include <vector>

class SparseMatrix {
private:
  std::vector<int> row_indices;
  std::vector<int> col_indices;
  std::vector<int> values;
  int rows;
  int cols;
  int non_zero;

public:
  SparseMatrix(int r, int c) : rows(r), cols(c), non_zero(0) {}

  void insert(int row, int col, int value) {
    row_indices.push_back(row);
    col_indices.push_back(col);
    values.push_back(value);
    non_zero++;
  }

  void transpose() {
    for (int i = 0; i < non_zero; ++i) {
      std::swap(row_indices[i], col_indices[i]);
    }
  }

  void display() {
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        int idx = -1;
        for (int k = 0; k < non_zero; ++k) {
          if (row_indices[k] == i && col_indices[k] == j) {
            idx = k;
            break;
          }
        }
        if (idx != -1) {
          std::cout << values[idx] << " ";
        } else {
          std::cout << "0 ";
        }
      }
      std::cout << std::endl;
    }
  }

  static SparseMatrix add(const SparseMatrix &A, const SparseMatrix &B);
  static SparseMatrix multiply(const SparseMatrix &A, const SparseMatrix &B);
};

SparseMatrix SparseMatrix::add(const SparseMatrix &A, const SparseMatrix &B) {
  if (A.rows != B.rows || A.cols != B.cols) {
    std::cerr << "Matrix dimensions don't match for addition." << std::endl;
    exit(1);
  }

  SparseMatrix result(A.rows, A.cols);

  int idxA = 0, idxB = 0;

  while (idxA < A.non_zero && idxB < B.non_zero) {
    if (A.row_indices[idxA] < B.row_indices[idxB] ||
        (A.row_indices[idxA] == B.row_indices[idxB] &&
         A.col_indices[idxA] < B.col_indices[idxB])) {
      result.insert(A.row_indices[idxA], A.col_indices[idxA], A.values[idxA]);
      idxA++;
    } else if (A.row_indices[idxA] > B.row_indices[idxB] ||
               (A.row_indices[idxA] == B.row_indices[idxB] &&
                A.col_indices[idxA] > B.col_indices[idxB])) {
      result.insert(B.row_indices[idxB], B.col_indices[idxB], B.values[idxB]);
      idxB++;
    } else {
      result.insert(A.row_indices[idxA], A.col_indices[idxA],
                    A.values[idxA] + B.values[idxB]);
      idxA++;
      idxB++;
    }
  }

  while (idxA < A.non_zero) {
    result.insert(A.row_indices[idxA], A.col_indices[idxA], A.values[idxA]);
    idxA++;
  }

  while (idxB < B.non_zero) {
    result.insert(B.row_indices[idxB], B.col_indices[idxB], B.values[idxB]);
    idxB++;
  }

  return result;
}

SparseMatrix SparseMatrix::multiply(const SparseMatrix &A,
                                    const SparseMatrix &B) {
  if (A.cols != B.rows) {
    std::cerr << "Matrix dimensions don't match for multiplication."
              << std::endl;
    exit(1);
  }

  SparseMatrix result(A.rows, B.cols);

  for (int i = 0; i < A.non_zero; ++i) {
    for (int j = 0; j < B.non_zero; ++j) {
      if (A.col_indices[i] == B.row_indices[j]) {
        result.insert(A.row_indices[i], B.col_indices[j],
                      A.values[i] * B.values[j]);
      }
    }
  }

  return result;
}

int main() {
  int rows = 3, cols = 3;

  SparseMatrix A(rows, cols);
  A.insert(0, 0, 1);
  A.insert(0, 2, 3);
  A.insert(1, 1, 5);
  A.insert(2, 0, 7);

  SparseMatrix B(rows, cols);
  B.insert(0, 1, 2);
  B.insert(1, 0, 4);
  B.insert(1, 1, 6);
  B.insert(2, 2, 8);

  std::cout << "Matrix A:" << std::endl;
  A.display();

  std::cout << "\nMatrix B:" << std::endl;
  B.display();

  SparseMatrix C = SparseMatrix::add(A, B);
  std::cout << "\nMatrix C (A + B):" << std::endl;
  C.display();

  SparseMatrix D = SparseMatrix::multiply(A, B);
  std::cout << "\nMatrix D (A * B):" << std::endl;
  D.display();

  return 0;
}
