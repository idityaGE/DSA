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

// brute using stack
Node *reverse_stack(Node *head) {
  if (!head || !head->next) return head;
  stack<int> st;
  Node *temp = head;
  while (temp != nullptr) {
    st.push(temp->data);
    temp = temp->next;
  }
  temp = head;
  while (temp != nullptr) {
    temp->data = st.top();
    st.pop();
    temp = temp->next;
  }
  return head;
}

// optimal iterative
Node *reverseLinkedList(Node *head) {
  if (!head || !head->next)
    return head;
  Node *curr, *back, *front;
  curr = head;
  back = nullptr;
  front = head->next;

  while (front != nullptr) {
    curr->next = back;
    back = curr;
    curr = front;
    front = front->next;
  }
  curr->next = back;

  return curr;
}
// recursive
Node *reverseLinkedList_recursive(Node *head) {
  if (!head || !head->next)
    return head;
  Node *newHead = reverseLinkedList_recursive(head->next);
  Node *front = head->next;
  front->next = head;
  head->next = nullptr;
  return newHead;
}

int main() {
  vector<int> arr = {1, 3, 5, 2, 6};
  Node *head = constructLL(arr);

  head = reverseLinkedList_recursive(head);
  print(head);
  cout << endl;
  return 0;
}