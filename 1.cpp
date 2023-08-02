// 1) Developa Menudrivenprogramtodemonstrate the followingoperations of Arrays
// ——MENU——-
// 1.CREATE
// 2.DISPLAY
// 3.INSERT
// 4.DELETE
// 5.LINEAR SEARCH
// 6.EXIT

#include <iostream>

void create() { std::cout << "Array has been created" << std::endl; }

void display(int arr[], int size) {
  for (size_t i = 0; i < size; i++)
    std::cout << arr[i] << " ";
  std::cout << std::endl;
}

void insert(int arr[], int index, int value, int &size) {

  if ((index > size) || (index < 0)) {
    std::cout << "Can't insert element at that index" << std::endl;
    return;
  }
  for (size_t i = size - 1; i >= index; i--) {
    arr[i + 1] = arr[i];
  }
  arr[index] = value;
  size++;
  std::cout << "Value is inserted" << std::endl;
  display(arr, size);
}

void deleteElement(int arr[], int index, int &size) {
  if (index < 0) {
    std::cout << "Cannot deleted element from that index" << std::endl;
    return;
  }
  for (size_t i = index; i < size; i++) {
    arr[i] = arr[i + 1];
  }
  size--;
  display(arr, size);
}

int linearSearch(int arr[], int key, int &size) {
  for (size_t i = 0; i < size; i++) {
    if (arr[i] == key)
      return i;
  }
  return -1;
}

int main() {

  int arr[100] = {10, 20, 30, 40, 50};
  int size = 5;
  int index, value;
  std::cout << "1.Create\n"
            << "2.Display\n"
            << "3.Insert\n"
            << "4.Delete\n"
            << "5.Linear Search\n"
            << "6.Exit" << std::endl;
  int choice;
  int c = 0;
  while (c == 0) {
    std::cin >> choice;
    switch (choice) {
    case 1:
      create();
      break;
    case 2:
      display(arr, size);
      break;
    case 3:
      std::cout << "Enter the index and the value to be inserted" << std::endl;
      std::cin >> index >> value;
      insert(arr, index, value, size);
      break;
    case 4:
      std::cout << "Enter the index at which the value should be deleted"
                << std::endl;
      std::cin >> index;
      deleteElement(arr, index, size);
      break;
    case 5:
      linearSearch(arr, 6, size);
      break;
    case 6:
      c++;
      break;
      return 0;
    }
  }
  return 0;
}
