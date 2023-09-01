// Write a program to convert an Infix expression into a Postfix expression.
#include <iostream>
#include <stack>
#include <string>

int getPrecedence(char op) {
  if (op == '^')
    return 3;
  if (op == '*' || op == '/')
    return 2;
  if (op == '+' || op == '-')
    return 1;
  return -1;
}

int main() {
  std::string expression;
  std::cout << "Enter the expression: ";
  std::cin >> expression;
  expression.push_back(')'); // Append ')' to the input expression
  std::cout << "Infix Expression: " << expression << std::endl;

  std::stack<char> process;
  process.push('(');

  std::string result;

  for (int i = 0; i < expression.length(); i++) {
    char ch = expression[i];
    if (ch == '(')
      process.push(ch);
    else if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
      result.push_back(ch);
    else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
      // Operator encountered
      while (getPrecedence(ch) <= getPrecedence(process.top()) && process.top() != '(') {
        result.push_back(process.top());
        process.pop();
      }
      process.push(ch);
    }
    else if (ch == ')') {
      while (process.top() != '(') {
        result.push_back(process.top());
        process.pop();
      }
      process.pop(); // Remove the '(' from the stack
    }
  }

  // Pop any remaining operators from the stack and append them to the result
  while (!process.empty()) {
    if (process.top() != '(')
      result.push_back(process.top());
    process.pop();
  }

  std::cout << "Postfix Expression: " << result << std::endl;
  return 0;
}
