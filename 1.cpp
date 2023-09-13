// Develop a menu driven program for the following operations of on a Singly
// Linked List. (a) Insertion at the beginning. (b) Insertion at the end. (c)
// Insertion in between (before or after a node having a specific value, say
// 'Insert a new Node 35 before/after the Node 30'). (d) Deletion from the
// beginning. (e) Deletion from the end. (f) Deletion of a specific node, say
// 'Delete Node 60'). (g) Search for a node and display its position from head.
// (h) Display all the node values

#include <algorithm>
#include <iostream>

class Node {
public:
  int data;
  Node *next;

  // constructor
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
  // destructor
  ~Node() {
    int value = this->data;
    if (this->next != NULL) {
      delete next;
      this->next = NULL;
    }
    std::cout << "Memory is free for node with data" << std::endl;
  }
};

void insertAtHead(Node *&head, int data) {
  // new node create
  Node *temp = new Node(data);
  temp->next = head;
  head = temp;
}

void insertAtTail(Node *&tail, int data) {
  Node *temp = new Node(data);
  tail->next = temp;
  tail = temp;
}

void print(Node *head) {
  Node *temp = head;
  while (temp != NULL) {
    std::cout << temp->data << " ";
    temp = temp->next;
  }
  std::cout << std::endl;
}

void insertAtPosition(Node *&head, Node *&tail, int position, int data) {
  // insert at starting case
  if (position == 1) {
    insertAtHead(head, data);
    return;
  }
  Node *nodeToInsert = new Node(data);
  Node *temp = head;
  int cnt = 1;
  while (cnt < position - 1) {
    temp = temp->next;
    cnt++;
  }
  // insert at last position
  if (temp->next == NULL) {
    insertAtTail(tail, data);
    return;
  }
  nodeToInsert->next = temp->next;
  temp->next = nodeToInsert;
}

void deleteNode(Node *&head, Node *&tail, int position) {
  // deleting first or last node
  if (position == 1) {
    Node *temp = head;
    head = head->next;
    // Memory free from node
    temp->next = NULL;
    delete temp;
    // Check if the list is empty
    if (head == NULL) {
      tail = NULL;
    }
  } else {
    // deleting any middle node or last node
    Node *current = head;
    Node *previous = NULL;
    int cnt = 1;
    while (cnt < position) {
      previous = current;
      current = current->next;
      cnt++;
    }
    previous->next = current->next;
    current->next = NULL;
    delete current;
    // Check if the deleted node was the last node
    if (previous->next == NULL) {
      tail = previous;
    }
  }
}

int main() {
  int data, position;
  Node *head = NULL;
  Node *tail = NULL;
  std::cout << "1) Insertion at the beginning\n"
            << "2) Insertion at the end\n"
            << "3) insertion in between\n"
            << "4) Deletion from the beginning\n"
            << "5) Deletion from the end\n"
            << "6) Deletion of a specific node\n"
            << "7) Search for a node and display it\n"
            << "8) Display all the node values\n";
  int choice;
  std::cin >> choice;
  switch (choice) {
  case 1:
    std::cout << "What to insert:";
    std::cin >> data;
    insertAtHead(head, data);
    break;
  case 2:
    std::cout << "What to insert:";
    std::cin >> data;
    insertAtTail(tail, data);
    break;
  case 3:
    insertAtPosition(head, tail, position, data);
    break;
  case 4:
    deleteNode(head, data);
    break;
  case 5:
    deleteNode(head, tail, position);
    break;
  case 6:
    std::cout << "Enter the position:";
    std::cin >> position;
    deleteNode(head, tail, position);
    break;
  case 7:

    break;
  case 8:
    break;
  }
  return 0;
}
