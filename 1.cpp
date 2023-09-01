// Develop a menu driven program demonstrating the following operations on a
// Stack using array: (i) push(), (ii) pop(), (iii) isEmpty(), (iv) isFull(),
// (v) display(), and (vi) peek().
#include <iostream>
#include <limits>

void choices() {
  std::cout << "1. PUSH\n"
            << "2. POP\n"
            << "3. isEMPTY\n"
            << "4. isFULL\n"
            << "5. DISPLAY\n"
            << "6. PEEK\n"
            << "7. EXIT" << std::endl;
}

// void clearInputBuffer() {
//   std::cin.clear();
//   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
// }

void push(int s[], int size, int &top) {
  if (top == size - 1) {
    std::cout << "OVERFLOW CONDITION" << std::endl;
    return;
  } else {
    top++;
    std::cout << "Enter the element : " << std::endl;
    int x;
    std::cin >> x;
    s[top] = x;
  }
}

void pop(int s[], int &top) {
  if (top == -1) {
    std::cout << "UNDERFLOW CONDITION" << std::endl;
    return;
  } else {
    int x = s[top];
    top--;
    std::cout << "POPPED : " << x << std::endl;
  }
}

void isEmpty(int &top) {
  if (top == -1) {
    std::cout << "TRUE" << std::endl;
  } else {
    std::cout << "FALSE" << std::endl;
  }
}

void isFull(int size, int &top) {
  if (top == size - 1) {
    std::cout << "TRUE" << std::endl;
    ;
  } else {
    std::cout << "FALSE" << std::endl;
  }
}

void display(int s[], int top) {
  std::cout << "[";
  for (int i = top; i >= 0; i--) {
    std::cout << s[i] << ",";
  }
  std::cout << "]" << std::endl;
}

void peek(int s[], int top) {
  if (top == -1) {
    std::cout << "Stack is empty" << std::endl;
  } else {
    std::cout << "Element is : " << s[top] << std::endl;
  }
}

int main() {
  int stack[10], size = 10, top = -1;
  bool loop = true;
  while (loop) {
    int choice = 0;
    choices();
    std::cin >> choice;
    // clearInputBuffer();
    std::fflush(stdin);
    switch (choice) {
    case 1:
      push(stack, size, top);
      break;
    case 2:
      pop(stack, top);
      break;
    case 3:
      isEmpty(top);
      break;
    case 4:
      isFull(size, top);
      break;
    case 5:
      display(stack, top);
      break;
    case 6:
      peek(stack, top);
      break;
    case 7:
      loop = false;
      break;
    default:
      std::cout << "Invalid Option" << std::endl;
    }
  }
  return 0;
}
