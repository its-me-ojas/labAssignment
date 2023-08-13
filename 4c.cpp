// Write a program to delete all the vowels from the string
#include <iostream>
#include <string>

void deleteVowel(std::string &s) {
  std::string vowels = "aeiouAEIOU";
  int i = 0;
  while (i < s.length()) {
    // here the vowels.find searches the char s[i] in the vowels
    // if its there then
    if (vowels.find(s[i]) != std::string::npos)
      // using this the vowel is erased from the string
      s.erase(i, 1);
    else
      i++;
  }
}

int main() {
  std::string str;
  std::cout << "Enter your string : ";
  std::getline(std::cin, str);
  std::cout << str << std::endl;
  deleteVowel(str);
  std::cout << str << std::endl;
  return 0;
}
