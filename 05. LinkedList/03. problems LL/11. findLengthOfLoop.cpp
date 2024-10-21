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

// brute [Hashing]
int lengthOfLoop(Node *head) {
  unordered_map<Node *, int> visitedNodes;
  Node *temp = head;
  int timer = 0;
  while (temp != NULL) {
    if (visitedNodes.find(temp) != visitedNodes.end()) {
      int loopLength = timer - visitedNodes[temp];
      return loopLength;
    }
    visitedNodes[temp] = timer;
    temp = temp->next;
    timer++;
  }
  return 0;
}

// optimal approch [ Tortoise and Hare Algorithm ]
int findLen(Node *slow, Node *fast) {
  int cnt = 1;
  fast = fast->next;
  while (slow != fast) {
    cnt++;
    fast = fast->next;
  }
  return cnt;
}
int lengthOfLoop(Node *head) {
  if (head == nullptr || head->next == nullptr)
    return 0;
  Node *slow = head;
  Node *fast = head;
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
      return findLen(slow, fast);
  }
  return 0;
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
4
4 10 3 5
2
Sample Output 1:
3
Explanation Of Sample Input 1 :
The cycle is 10, 3, 5.
*/