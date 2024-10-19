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

// brute
Node *removeKthNode_brute(Node *head, int K) {
  if (!head) return head;
  Node *temp = head;
  int len = 0;
  while (temp != nullptr) {
    len++;
    temp = temp->next;
  }

  if (len == K) {
    Node *newHead = head->next;
    delete head;
    return newHead;
  }

  int res = len - K;
  temp = head;
  while (temp != nullptr) {
    res--;
    if (res == 0) break;
    temp = temp->next;
  }

  Node *delNode = temp->next;
  temp->next = delNode->next;
  delNode->next = nullptr;
  delete delNode;
  return head;
}

Node *removeKthNode(Node *head, int K) {
  Node *fast = head;
  Node *slow = head;
  for (int i = 0; i < K; i++)
    fast = fast->next;

  if (!fast) {
    Node *newHead = head->next;
    head->next = nullptr;
    delete head;
    return newHead;
  }

  while (fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next;
  }

  Node *delNode = slow->next;
  slow->next = delNode->next;
  delNode->next = nullptr;
  delete delNode;
  return head;
}

int main() {
  vector<int> arr = {1, 3, 5, 2, 6};
  Node *head = constructLL(arr);

  print(head);
  cout << endl;
  return 0;
}