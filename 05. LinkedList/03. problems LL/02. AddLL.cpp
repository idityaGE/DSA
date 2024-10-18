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

Node *constructDLL(vector<int> &arr) {
  if (arr.empty()) return nullptr;
  Node *head = new Node(arr[0]);
  Node *curr = head;
  for (int i = 1; i < arr.size(); i++)
    curr = curr->next = new Node(arr[i]);
  return head;
}

Node *addTwoNumbers(Node *num1, Node *num2) {
  Node *t1 = num1, *t2 = num2;
  Node *dummy = new Node(-1);
  Node *curr = dummy;
  int n1, n2, carry = 0, sum, rem;

  while (t1 != nullptr || t2 != nullptr || carry != 0) {
    n1 = (t1 != nullptr) ? t1->data : 0;
    n2 = (t2 != nullptr) ? t2->data : 0;

    sum = n1 + n2 + carry;
    rem = sum % 10;
    carry = sum / 10;

    curr->next = new Node(rem);
    curr = curr->next;

    if (t1 != nullptr)
      t1 = t1->next;
    if (t2 != nullptr)
      t2 = t2->next;
  }

  if (carry)
    curr->next = new Node(carry);

  return dummy->next;  // Return the head of the resulting list
}

int main() {
  vector<int> arr1 = {1, 3, 5, 2, 6};
  vector<int> arr2 = {1, 3, 5, 2, 6};

  Node *head1 = constructDLL(arr1);
  Node *head2 = constructDLL(arr2);

  Node *addedNode = addTwoNumbers(head1, head2);
  print(addedNode);
  cout<< endl;

  return 0;
}