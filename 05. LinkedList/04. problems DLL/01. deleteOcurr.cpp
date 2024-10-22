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
Node *deleteAllOccurrences(Node *head, int k) {
  Node *temp = head;
  while (temp != nullptr) {
    if (temp->data == k) {
      if (temp == head)
        head = head->next;
      Node *front = temp->next;
      Node *back = temp->prev;
      if (front)
        front->prev = back;
      if (back)
        back->next = front;
      free(temp);
      temp = front;
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