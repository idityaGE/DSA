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

// Brute
Node *oddEvenList_Brute(Node *head) {
  vector<int> arr;

  Node *temp = head;
  while (temp != nullptr && temp->next != nullptr) {
    arr.push_back(temp->data);
    temp = temp->next->next;
  }
  if (temp)
    arr.push_back(temp->data);

  temp = head->next;
  while (temp != nullptr && temp->next != nullptr) {
    arr.push_back(temp->data);
    temp = temp->next->next;
  }
  if (temp)
    arr.push_back(temp->data);

  temp = head;
  int i = 0;
  while (temp != nullptr) {
    temp->data = arr[i++];
    temp = temp->next;
  }
  return head;
}

Node *oddEvenList(Node *head) {
  if (head == nullptr || head->next == nullptr)
    return head;
  Node *odd, *even, *evenHead;
  odd = head;
  even = head->next;
  evenHead = head->next;

  while (even != nullptr && even->next != nullptr) {
    odd->next = odd->next->next;
    even->next = even->next->next;

    odd = odd->next;
    even = even->next;
  }
  odd->next = evenHead;
  return head;
}

int main() {
  vector<int> arr = {1, 3, 5, 2, 6};
  Node *head = constructLL(arr);

  head = oddEvenList(head);

  print(head);

  cout << endl;

  return 0;
}

/*
Sample Input 1:
5
2 4 6 8 10
Sample Output 1:
2 6 10 4 8
Explanation Of Sample Input 1 :
The reordered list groups nodes with odd indices (2, 6, and 10) followed by nodes with even indices (4 and 8). So, the reordered list will look like: 2 -> 6 -> 10 -> 4 -> 8.
*/