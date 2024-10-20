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

Node *deleteMiddle(Node *head) {
  if (!head || !head->next)
    return nullptr;

  Node *slow = head;
  Node *fast = head->next;
  while (fast->next != nullptr && fast->next->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }

  Node *temp = slow->next;
  slow->next = slow->next->next;
  temp->next = nullptr;
  delete temp;
  return head;
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
5
1 2 3 4 5
Sample Output 1 :
1 2 4 5
Explanation to Sample Input 1 :
We can clearly see that there are 5 nodes in the linked list therefore the middle node is the node with value '3'.
*/