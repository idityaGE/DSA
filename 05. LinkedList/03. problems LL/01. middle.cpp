#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node *next;

  Node(int val)
      : data(val), next(nullptr) {}
};

Node *constructLL(vector<int> &arr) {
  if (arr.empty()) return nullptr;
  Node *head = new Node(arr[0]);
  Node *curr = head;
  for (int i = 1; i < arr.size(); i++)
    curr = curr->next = new Node(arr[i]);
  return head;
}

int middle(Node *head) {
  if (head == nullptr) return 0;
  Node *slow, *fast;
  slow = fast = head;
  while (fast != nullptr && fast->next != nullptr)
    slow = slow->next, fast = fast->next->next;
  return slow->data;
}

int main() {
  vector<int> arr = {1, 3, 5, 7, 23};
  Node *head = constructLL(arr);
  cout << middle(head);
  return 0;
}