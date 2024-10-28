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

// LL is sorted
// brute force O(n^2)
vector<pair<int, int>> findPairs(Node *head, int k) {
  vector<pair<int, int>> ans;
  Node *temp1 = head;
  while (temp1 != nullptr) {
    Node *temp2 = temp1->next;
    while (temp2 != nullptr && temp1->data + temp2->data <= k) {
      if (temp1->data + temp2->data == k)
        ans.push_back({temp1->data, temp2->data});
      temp2 = temp2->next;
    }
    temp1 = temp1->next;
  }
  return ans;
}

// two pointer
vector<pair<int, int>> findPairs(Node *head, int k) {
  vector<pair<int, int>> ans;
  if (head == nullptr)
    return ans;
  Node *right = head;
  Node *left = head;
  while (right->next != nullptr)
    right = right->next;
  while (left->data < right->data) {
    if (left->data + right->data == k) {
      ans.push_back({left->data, right->data});
      left = left->next;
      right = right->prev;
    } else if (left->data + right->data < k)
      left = left->next;
    else
      right = right->prev;
  }
  return ans;
}

int main() {
  vector<int> arr = {1, 3, 5, 2, 6};
  Node *head = convertArrToDLL(arr);

  print(head);
  return 0;
}