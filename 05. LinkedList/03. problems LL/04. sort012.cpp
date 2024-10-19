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

// brute
Node *sortList_brute(Node *head) {
  int cnt0, cnt1, cnt2;
  cnt0 = cnt1 = cnt2 = 0;

  Node *temp = head;
  while (temp != nullptr) {
    int n = temp->data;
    switch (n) {
      case 0:
        cnt0++;
        break;
      case 1:
        cnt1++;
        break;
      case 2:
        cnt2++;
        break;
    }
    temp = temp->next;
  }

  temp = head;
  while (temp != nullptr) {
    if (cnt0) {
      temp->data = 0;
      cnt0--;
    } else if (cnt1) {
      temp->data = 1;
      cnt1--;
    } else if (cnt2) {
      temp->data = 2;
      cnt2--;
    }
    temp = temp->next;
  }

  return head;
}

Node *sortList(Node *head) {
  if (head == nullptr || head->next == nullptr)
    return head;

  Node *zeroHead, *oneHead, *twoHead;
  zeroHead = new Node(-1);
  oneHead = new Node(-1);
  twoHead = new Node(-1);

  Node *zero = zeroHead;
  Node *one = oneHead;
  Node *two = twoHead;

  Node *temp = head;
  while (temp != nullptr) {
    if (temp->data == 0) {
      zero->next = temp;
      zero = zero->next;
    } else if (temp->data == 1) {
      one->next = temp;
      one = one->next;
    } else if (temp->data == 2) {
      two->next = temp;
      two = two->next;
    }
    temp = temp->next;
  }
  zero->next = (oneHead->next) ? (oneHead->next) : (twoHead->next);
  one->next = twoHead->next;
  two->next = nullptr;

  Node *newHead = zeroHead->next;

  delete zeroHead;
  delete oneHead;
  delete twoHead;

  return newHead;
}

int main() {
  vector<int> arr = {1, 0, 0, 1, 2, 2, 0, 1, 1};
  Node *head = constructDLL(arr);

  Node *newHead = sortList(head);

  print(newHead);
  cout << endl;

  return 0;
}

/*
Sample Input 1:
7
1 0 2 1 0 2 1
Sample Output 1:
0 0 1 1 1 2 2
Explanation Of Sample Input 1:
Input: 1 -> 0 -> 2 -> 1 -> 0 -> 2 -> 1
Output: 0 -> 0 -> 1 -> 1 -> 1 -> 2 -> 2
Explanation:
In this example, the original linked list contains two 0s, three 1s, and two 2s. The sorted linked list has all the 0s at the beginning, followed by all the 1s, and finally, all the 2s at the end.
*/