// Given a string, reverse it using STACK. For example “DataStructure” should be
// output as “erutcurtSataD.”
#include <iostream>
#include <stack>

void reverseString(std::string mainString, std::string &reverse) {
  std::stack<char> stk;

  for (size_t i = 0; i < mainString.length(); i++)
    // for pushing the string on to the stack
    stk.push(mainString[i]);
  for (size_t i = 0; i < mainString.length(); i++) {
    // taking out the string from the stack
    char c = stk.top();
    reverse[i] = c;
    stk.pop();
  }
}

int main() {

  std::string str = "DataStructure";
  std::string revstr = str;
  std::cout << str << std::endl;
  reverseString(str, revstr);
  std::cout << revstr << std::endl;
  return 0;
}
