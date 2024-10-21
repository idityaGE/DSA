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

// hashing method
bool detectCycle(Node *head) {
  if (!head)
    return false;
  Node *temp = head;
  unordered_map<Node *, int> mp;
  while (temp != nullptr) {
    if (mp.find(temp) != mp.end())
      return true;
    mp[temp] = 1;
    temp = temp->next;
  }
  return false;
}

// optimal approch [ Tortoise and Hare Algorithm ]
bool detectCycle(Node *head) {
  if (head == nullptr || head->next == nullptr)
    return false;
  Node *slow = head;
  Node *fast = head;
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
      return true;
  }
  return false;
}

int main() {
  vector<int> arr = {1, 3, 5, 2, 6};
  Node *head = constructLL(arr);

  print(head);
  cout << endl;
  return 0;
}

/*
Sample Input 1 :
1 2 3 4 -1
1
Sample Output 1 :
true
Explanation of Sample Input 1:
The linked list given in the input is as follows:

1 -> 2 -> 3 -> 4
     ^         |
     |         |
     -----------
*/