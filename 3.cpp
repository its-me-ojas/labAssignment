// Write a program that checks if an expression has balanced parentheses.

#include <iostream>
#include <stack>
#include <string>

bool areParenthesesBalanced(const std::string &expression) {
  std::stack<char> parenthesesStack;

  for (char ch : expression) {
    if (ch == '(' || ch == '[' || ch == '{') {
      parenthesesStack.push(ch);
    } 
    else if (ch == ')' || ch == ']' || ch == '}') {
      if (parenthesesStack.empty()) {
        return false; // Unbalanced, as there's no matching opening parenthesis
      }

      char top = parenthesesStack.top();
      parenthesesStack.pop();
      std::cout << ch << "," << top << std::endl;
      if ((ch == ')' && top != '(') || (ch == ']' && top != '[') ||
          (ch == '}' && top != '{')) {
        return false; // Mismatched parentheses
      }
    }
  }

  return parenthesesStack
      .empty(); // If stack is empty, all parentheses are balanced
}

int main() {
  std::string expression;
  std::cout << "Enter an expression: ";
  std::getline(std::cin, expression);

  if (areParenthesesBalanced(expression)) {
    std::cout << "Parentheses are balanced." << std::endl;
  } else {
    std::cout << "Parentheses are not balanced." << std::endl;
  }

  return 0;
}
