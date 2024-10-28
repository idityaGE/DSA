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

Node *reverse(Node *head) {
  Node *temp = head;
  Node *prev = nullptr;
  while (temp != NULL) {
    Node *front = temp->next;
    temp->next = prev;
    prev = temp;
    temp = front;
  }
  return prev;
}

Node *getKthNode(Node *head, int k) {
  k -= 1;
  Node *temp = head;
  while (temp != nullptr && k > 0) {
    k--;
    temp = temp->next;
  }
  return temp;
}

Node *kReverse(Node *head, int k) {
  Node *temp = head;
  Node *prev = nullptr;
  while (temp != nullptr) {
    Node *kthNode = getKthNode(temp, k);
    if (kthNode == nullptr) {
      if (prev) prev->next = temp;
      break;
    }
    Node *nextNode = kthNode->next;
    kthNode->next = nullptr;
    reverse(temp);
    if (temp == head)
      head = kthNode;
    else
      prev->next = kthNode;

    prev = temp;
    temp = nextNode;
  }
  return head;
}

int main() {
  vector<int> arr = {1, 3, 5, 2, 6};
  Node *head = convertArrToDLL(arr);
  head = kReverse(head, 3);

  print(head);
  return 0;
}
