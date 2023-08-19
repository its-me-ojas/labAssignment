// diagonal matrix
#include <iostream>
#include <vector>

void printArray(std::vector<int> array, int size) {
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      if (i == j)
        std::cout << array[i] << " ";
      else
        std::cout << "0 ";
    }
    std::cout << std::endl;
  }
}

int main() {

  std::vector<int> diagonalElements;
  std::cout << "Enter the size of the array : ";
  size_t size;
  std::cin >> size;

  for (size_t i = 0; i < size; i++) {
    int element;
    std::cout << i + 1 << " element : ";
    std::cin >> element;
    diagonalElements.push_back(element);
  }

  printArray(diagonalElements, size);

  return 0;
}
