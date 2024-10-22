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

// hashing
Node *firstNode(Node *head) {
  if (!head)
    return nullptr;
  map<Node *, int> mp;
  Node *temp = head;
  while (temp != nullptr) {
    if (mp.find(temp) != mp.end())
      return temp;
    mp[temp] = 1;
    temp = temp->next;
  }
  return nullptr;
}

// optimal
Node *firstNode(Node *head) {
  if (!head)
    return nullptr;
  Node *slow = head;
  Node *fast = head;
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      slow = head;
      while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
      }
      return slow;
    }
  }
  return nullptr;
}

int main() {
  vector<int> arr = {1, 3, 5, 2, 6};
  Node *head = constructLL(arr);

  print(head);
  cout << endl;
  return 0;
}