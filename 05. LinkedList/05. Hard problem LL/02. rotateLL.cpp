#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node *next;

  Node(int val)
      : data(val), next(nullptr) {}
  Node(int val, Node *nextNode)
      : data(val), next(nextNode) {}
};

void print(Node *head) {
  if (head == nullptr) return;
  Node *temp = head;
  while (temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

Node *constructLL(vector<int> &arr) {
  if (arr.empty()) return nullptr;
  Node *head = new Node(arr[0]);
  Node *curr = head;
  for (int i = 1; i < arr.size(); i++)
    curr = curr->next = new Node(arr[i]);
  return head;
}

Node *rotate(Node *head, int k) {
  if (head == nullptr || k == 0)
    return head;

  Node *temp = head;
  int len = 1;
  while (temp->next != nullptr) {
    len++;
    temp = temp->next;
  }

  k = k % len;
  if (k == 0)
    return head;

  temp->next = head;

  int stepsToNewHead = len - k;
  temp = head;
  for (int i = 1; i < stepsToNewHead; i++)
    temp = temp->next;

  head = temp->next;
  temp->next = nullptr;

  return head;
}

int main() {
  vector<int> arr = {1, 3, 5, 2, 6};
  Node *head = constructLL(arr);

  print(head);
  cout << endl;
  return 0;
}