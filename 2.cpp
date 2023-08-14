// Given a string, reverse it using STACK. For example “DataStructure” should be
// output as “erutcurtSataD.”
#include <iostream>
#include <stack>

void reverseString(std::stack<char> stk, std::string mainString,
                   std::string &reverse) {
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
  std::stack<char> stk;
  std::cout << str << std::endl;
  reverseString(stk, str, revstr);
  std::cout << revstr << std::endl;
  return 0;
}
