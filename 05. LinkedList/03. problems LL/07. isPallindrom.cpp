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

bool isPalindrome(Node *head) {
  if (!head || !head->next) return true;
  Node *temp = head;
  stack<int> st;

  while (!temp) {
    st.push(temp->data);
    temp = temp->next;
  }

  temp = head;
  while (!temp) {
    if (temp->data != st.top())
      return false;
    st.pop();
    temp = temp->next;
  }
  return true;
}

Node *reverseLL(Node *head) {
  if (!head || !head->next)
    return head;
  Node *newHead = reverseLL(head->next);
  Node *front = head->next;
  front->next = head;
  head->next = nullptr;
  return newHead;
}

bool isPalindrome_optimal(Node *head) {
  if (!head || !head->next)
    return true;
  Node *slow = head;
  Node *fast = head;

  // we need to stop before the slow reaches to middle node
  while (fast->next != nullptr && fast->next->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }

  // reverse from middle
  Node *newHead = reverseLL(slow->next);
  Node *first = head;
  Node *second = newHead;

  while (second != nullptr) {
    if (first->data != second->data) {
      reverseLL(newHead);
      return false;
    }
    first = first->next;
    second = second->next;
  }
  reverseLL(newHead);
  return true;
}

int main() {
  vector<int> arr = {1, 3, 5, 3, 1};
  Node *head = constructLL(arr);

  cout << isPalindrome_optimal(head);
  cout << endl;
  return 0;
}