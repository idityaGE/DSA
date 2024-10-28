#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node *next;
  Node *child;

  Node(int val)
      : data(val), next(nullptr), child(nullptr) {}
  Node(int val, Node *nextNode, Node *child)
      : data(val), next(nextNode), child(child) {}
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

Node *merge2List(Node *first, Node *second) {
  Node *t1 = first, *t2 = second, *temp = nullptr;
  Node *dummyNode = new Node(-1);
  temp = dummyNode;
  while (t1 != nullptr && t2 != nullptr) {
    if (t1->data < t2->data) {
      temp->child = t1;
      temp = t1;
      t1 = t1->child;
    } else {
      temp->child = t2;
      temp = t2;
      t2 = t2->child;
    }
    temp->next = nullptr;
  }
  if (t1)
    temp->child = t1;
  if (t2)
    temp->child = t2;
  if (dummyNode->child)
    dummyNode->child->next = nullptr;
  return dummyNode->child;
}

Node *flattenLinkedList(Node *head) {
  if (head == nullptr || head->next == nullptr)
    return head;
  Node *mergedHead = flattenLinkedList(head->next);
  return merge2List(head, mergedHead);
}

int main() {
  vector<int> arr = {1, 3, 5, 2, 6};
  Node *head = constructLL(arr);

  print(head);
  cout << endl;
  return 0;
}