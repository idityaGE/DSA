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

Node *sortTwoLists(Node *first, Node *second) {
  Node *t1 = first, *t2 = second, *temp = nullptr;
  // using dummyNode concept, No need to create a new Node
  Node *dummyNode = new Node(-1);
  temp = dummyNode;
  while (t1 != nullptr && t2 != nullptr) {
    if (t1->data < t2->data) {
      temp->next = t1;
      temp = t1;
      t1 = t1->next;
    } else {
      temp->next = t2;
      temp = t2;
      t2 = t2->next;
    }
  }
  if (t1)
    temp->next = t1;
  if (t2)
    temp->next = t2;
  return dummyNode->next;
}

int main() {
  vector<int> arr = {1, 3, 5, 2, 6};
  Node *head = constructLL(arr);

  print(head);
  cout << endl;
  return 0;
}