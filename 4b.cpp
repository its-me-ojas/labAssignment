#include <fstream>
#include <iostream>
#include <string>

int main() {

  std::cout << "Enter the string : ";
  std::string str;
  std::getline(std::cin, str);
  std::cout << "Original String : " << str << std::endl;
  int i = 0, j = str.length() - 1;
  while (i < j) {
    std::swap(str[i++], str[j--]);
  }
  std::cout << "Reversed String : " << str << std::endl;

  return 0;
}
