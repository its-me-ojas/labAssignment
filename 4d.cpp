// Write a program to sort the strings in alphabetical order
#include <fstream>
#include <iostream>

void sortAlphabeticalOrder(std::string &s) {
  for (size_t i = 0; i < s.length() - 1; i++) {
    for (size_t j = 0; j < s.length() - i - 1; j++) {
      if (s[j] > s[j + 1])
        std::swap(s[j], s[j + 1]);
    }
  }
}

int main() {
  std::string str;
  std::cout << "Enter the string : ";
  std::getline(std::cin, str);
  std::cout << str << std::endl;
  sortAlphabeticalOrder(str);
  std::cout << str << std::endl;
  return 0;
}
