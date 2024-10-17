#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node *next;
  Node *prev;

  Node(int val)
      : data(val), next(nullptr), prev(nullptr) {}
  Node(int val, Node *prevNode)
      : data(val), next(nullptr), prev(prevNode) {}
  Node(int val, Node *prevNode, Node *nextNode)
      : data(val), next(nextNode), prev(prevNode) {}
};
void print(Node *head) {
  if (head == nullptr) return;
  Node *temp = head;
  while (temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

Node *convertArrToDLL(vector<int> &arr) {
  if (arr.empty()) return nullptr;
  Node *head = new Node(arr[0]);
  Node *curr = head;
  for (int i = 1; i < arr.size(); i++)
    curr = curr->next = new Node(arr[i], curr);
  return head;
}

Node *deleteHead(Node *head) {
  if (head == nullptr) return nullptr;
  Node *temp = head;
  head = head->next;
  if (head != nullptr) head->prev = nullptr;
  delete temp;
  return head;
}

Node *deleteAtEnd(Node *head) {
  if (head == nullptr) return nullptr;
  if (head->next == nullptr) {
    delete head;
    return nullptr;
  }
  Node *temp = head;
  while (temp->next != nullptr)
    temp = temp->next;
  temp->prev->next = nullptr;
  delete temp;
  return head;
}

Node *deleteKey(Node *head, int key) {
  if (head == nullptr) return nullptr;
  if (head->data == key) {
    return deleteHead(head);
  }
  Node *temp = head;
  while (temp != nullptr && temp->data != key)
    temp = temp->next;
  if (temp == nullptr) return head;
  if (temp->prev != nullptr)
    temp->prev->next = temp->next;
  if (temp->next != nullptr)
    temp->next->prev = temp->prev;
  delete temp;
  return head;
}

int main() {
  vector<int> arr = {1, 3, 5, 2, 6};
  Node *head = convertArrToDLL(arr);
  // print(head);
  // head = deleteHead(head);
  // head = deleteAtEnd(head);
  head = deleteKey(head, 1);

  print(head);
  return 0;
}