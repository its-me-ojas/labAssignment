// Write a program to find the middle of a linked list.
// Input: 1->2->3->4->5
// Output- 3

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void createLinkedList(ListNode *&head, int n) {
  head = nullptr;
  for (int i = 0; i < n; i++) {
    ListNode *newNode = new ListNode(i);
    if (head == nullptr) {
      head = newNode;
    } else {
      ListNode *temp = head;
      while (temp->next != nullptr) {
        temp = temp->next;
      }
      temp->next = newNode;
    }
  }
}

void printLinkedList(ListNode *head) {
  ListNode *temp = head;
  while (temp != nullptr) {
    std::cout << temp->val << " -> ";
    temp = temp->next;
  }
  std::cout << std::endl;
}

int main() {
  ListNode *head;
  int n;
  std::cout << "Enter the length of the linked list:";
  std::cin >> n;

  createLinkedList(head, n);
  printLinkedList(head);

  if (head == nullptr) {
    return 0;
  }

  ListNode *slow = head;
  ListNode *fast = head->next;

  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }

  // slow now points to the middle node
  std::cout << "The middle element is " << slow->val << std::endl;
  return 0;
}
