// Write a program to concatenate one string to another string.
#include <iostream>
#include <string>
int main() {

  std::string str1, str2;
  std::cout << "enter string 1 : ";
  std::getline(std::cin, str1);
  std::cout << std::endl;
  std::cout << "enter string 2 : ";
  std::getline(std::cin, str2);
  std::string str3 = str1 + str2;
  std::cout << str3 << std::endl;

  return 0;
}
