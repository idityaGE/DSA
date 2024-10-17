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

Node *constructDLL(vector<int> &arr) {
  if (arr.empty()) return nullptr;
  Node *head = new Node(arr[0]);
  Node *curr = head;
  for (int i = 1; i < arr.size(); i++) {
    Node *newNode = new Node(arr[i]);
    newNode->prev = curr;
    curr->next = newNode;
    curr = newNode;
  }
  return head;
}

Node *reverseDLL(Node *head) {
  // Brute O(2n)
  // Node *temp = head;
  // stack<int> st;
  // while (temp != nullptr) {
  //   st.push(temp->data);
  //   temp = temp->next;
  // }
  // temp = head;
  // while (temp != nullptr) {
  //   temp->data = st.top();
  //   st.pop();
  //   temp = temp->next;
  // }
  // return head;

  if (head == nullptr) return nullptr;
  Node *temp = nullptr;
  Node *current = head;
  // Swap next and prev for all nodes
  while (current != nullptr) {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;  // Move to the next node (which is now `prev`)
  }
  // After the loop, temp will be the last node
  // To get the new head, return the previous node before null
  if (temp != nullptr) {
    head = temp->prev;
  }
  return head;
}

int main() {
  vector<int> arr = {1, 3, 5, 2, 6};
  Node *head = constructDLL(arr);
  print(head);
  cout << endl;

  head = reverseDLL(head);
  print(head);
  return 0;
}