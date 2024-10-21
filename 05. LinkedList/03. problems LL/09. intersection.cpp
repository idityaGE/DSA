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

// Hashing Method
Node *findIntersection(Node *firstHead, Node *secondHead) {
  if (!firstHead || !secondHead)
    return nullptr;
  map<Node *, int> mp;
  Node *temp = firstHead;
  while (temp != nullptr) {
    mp[temp] = 1;
    temp = temp->next;
  }
  temp = secondHead;
  while (temp != nullptr) {
    if (mp.find(temp) != mp.end())
      return temp;
    temp = temp->next;
  }
  return nullptr;
}

// Finding Diffrence Method
int getDifference(Node *head1, Node *head2) {
  int len1 = 0, len2 = 0;
  while (head1 != NULL || head2 != NULL) {
    if (head1 != NULL) {
      ++len1;
      head1 = head1->next;
    }
    if (head2 != NULL) {
      ++len2;
      head2 = head2->next;
    }
  }
  return len1 - len2;  // if difference is neg-> length of list2 > length of
                       // list1 else vice-versa
}
Node *findIntersection(Node *head1, Node *head2) {
  if (!head1 || !head2)
    return nullptr;
  int diff = getDifference(head1, head2);
  if (diff < 0)
    while (diff++ != 0)
      head2 = head2->next;
  else
    while (diff-- != 0)
      head1 = head1->next;

  while (head1 != NULL) {
    if (head1 == head2)
      return head1;
    head2 = head2->next;
    head1 = head1->next;
  }
  return nullptr;
}

// Optimal approch [cross travese]
Node *findIntersection(Node *firstHead, Node *secondHead) {
  if (!firstHead || !secondHead)
    return nullptr;
  Node *temp1 = firstHead;
  Node *temp2 = secondHead;
  while (temp1 != temp2) {
    temp1 = temp1->next;
    temp2 = temp2->next;

    if (temp1 == temp2)
      return temp1;
    if (temp1 == nullptr)
      temp1 = secondHead;
    if (temp2 == nullptr)
      temp2 = firstHead;
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