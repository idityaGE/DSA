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

struct ListNode {
  int val;
  ListNode *next;
  ListNode()
      : val(0), next(nullptr) {}
  ListNode(int x)
      : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next)
      : val(x), next(next) {}
};

// using priority queue
ListNode *mergeKLists(vector<ListNode *> &lists) {
  priority_queue<
      pair<int, ListNode *>,
      vector<pair<int, ListNode *>>,
      greater<pair<int, ListNode *>>
    > pq;
  for (int i = 0; i < lists.size(); i++) {
    if (lists[i])
      pq.push({lists[i]->val, lists[i]});
  }

  ListNode *dNode = new ListNode(-1);
  ListNode *temp = dNode;
  while (!pq.empty()) {
    auto it = pq.top();
    pq.pop();
    if (it.second->next)
      pq.push({it.second->next->val, it.second->next});
    temp->next = it.second;
    temp = temp->next;
  }
  return dNode->next;
}

int main() {
  vector<int> arr = {1, 3, 5, 2, 6};
  Node *head = constructLL(arr);

  print(head);
  cout << endl;
  return 0;
}

/*
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
*/