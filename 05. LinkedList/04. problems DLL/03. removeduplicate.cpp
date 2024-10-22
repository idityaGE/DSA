

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

//
Node *removeDuplicates(Node *head) {
  if (!head)
    return nullptr;
  Node *temp = head;
  while (temp != nullptr && temp->next != nullptr) {
    if (temp->data == temp->next->data) {
      Node *delNode = temp->next;
      temp->next = delNode->next;
      if (temp->next != nullptr)
        temp->next->prev = temp;
      delete delNode;
    } else
      temp = temp->next;
  }
  return head;
}

int main() {
  vector<int> arr = {1, 3, 5, 2, 6};
  Node *head = convertArrToDLL(arr);

  print(head);
  return 0;
}
