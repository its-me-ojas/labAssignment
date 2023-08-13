// Write a program to convert a character from uppercase to lowercase.
#include <iostream>

int main() {
  char c;
  std::cout << "enter a character : ";
  std::cin >> c;
  std::cout << "The character in lower case is : " << static_cast<char>(c + 32);
  return 0;
}
