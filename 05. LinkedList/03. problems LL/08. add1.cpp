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

// Brute approch
Node *reverseLL(Node *head) {
  if (head == nullptr || head->next == nullptr)
    return head;
  Node *newHead = reverseLL(head->next);
  Node *front = head->next;
  front->next = head;
  head->next = nullptr;
  return newHead;
}

Node *addOne_rev(Node *head) {
  head = reverseLL(head);
  int carry = 1;  // intialy 1 because we need to add 1 to the whole no.
  Node *temp = head;
  while (temp != nullptr) {
    temp->data = temp->data + carry;
    if (temp->data < 10) {
      carry = 0;
      break;
    } else {
      temp->data = 0;  // because we are add 1 so it can't be more than 10
      carry = 1;
    }
    temp = temp->next;
  }
  head = reverseLL(head);
  if (carry == 1) {
    Node *newNode = new Node(1);
    newNode->next = head;
    head = newNode;
  }
  return head;
}

// backtracking approch

int helper(Node *temp) {
  if (!temp)
    return 1;
  int carry = helper(temp->next);
  temp->data = temp->data + carry;
  if (temp->data < 10)
    return 0;
  else {
    temp->data = 0;
    return 1;
  }
}

Node *addOne(Node *head) {
  if (!head)
    return head;
  int carry = helper(head);
  if (carry == 1) {
    Node *newNode = new Node(1);
    newNode->next = head;
    head = newNode;
  }
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
Sample Input 1:
3
1 5 2
Sample Output 1:
1 5 3
Explanation For Sample Input 1:
Initially the number is 152. After incrementing it by 1, the number becomes 153.

Sample Input 2:
2
9 9
Sample Output 2:
1 0 0
Explanation For Sample Input 2:
Initially the number is 9. After incrementing it by 1, the number becomes 100. Please note that there were 2 nodes in the initial linked list, but there are three nodes in the sum linked list.
*/