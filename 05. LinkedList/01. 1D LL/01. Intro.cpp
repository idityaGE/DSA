#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node *next;

 public:
  Node(int val)
      : data(val), next(nullptr) {}
  Node(int val, Node *nextNode)
      : data(val), next(nextNode) {}
};

class LinkedList {
 private:
  Node *head;

 public:
  LinkedList()
      : head(nullptr) {}

  void insertAtEnd(int val) {
    Node *newNode = new Node(val);
    if (head == nullptr)
      head = newNode;
    else {
      Node *temp = head;
      while (temp->next != nullptr)
        temp = temp->next;
      temp->next = newNode;
    }
  }

  void insertAtBeginning(int val) {
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
  }

  void deleteNode(int val) {
    if (head == nullptr) return;
    if (head->data == val) {
      Node *nodeToDelete = head;
      head = head->next;
      delete nodeToDelete;
      return;
    }
    Node *temp = head;
    while (temp->next != nullptr && temp->next->data != val)
      temp = temp->next;
    if (temp->next == nullptr) return;
    Node *nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
  }

  void deleteAtEnd() {
    if (head == nullptr) return;
    if (head->next == nullptr) {
      delete head;
      head = nullptr;
      return;
    }
    Node *temp = head;
    while (temp->next->next != nullptr)
      temp = temp->next;
    Node *nodeToDel = temp->next;
    temp->next = nullptr;
    delete nodeToDel;
  }

  void deleteAtBeginning() {
    if (head == nullptr) return;
    Node *nodeToDel = head;
    head = head->next;
    delete nodeToDel;
  }

  bool search(int val) {
    Node *temp = head;
    while (temp != nullptr) {
      if (temp->data == val) return true;
      temp = temp->next;
    }
    return false;
  }

  void display() {
    Node *temp = head;
    while (temp != nullptr) {
      cout << temp->data << "  ";
      temp = temp->next;
    }
  }

  ~LinkedList() {
    Node *temp;
    while (head != nullptr) {
      temp = head;
      head = head->next;
      delete temp;
    }
  }
};

Node *constructLL(vector<int> &arr) {
  if (arr.empty()) return nullptr;
  Node *head = new Node(arr[0]);
  Node *temp = head;
  for (int i = 1; i < arr.size(); i++)
    temp = temp->next = new Node(arr[i]);
  return head;
}

int main() {
  LinkedList list;

  // Test Case 1: Insert at the end and display
  cout << "Test Case 1: Insert at end\n";
  list.insertAtEnd(10);
  list.insertAtEnd(20);
  list.insertAtEnd(30);
  list.display();  // Expected: 10  20  30
  cout << endl;

  // Test Case 2: Insert at the beginning and display
  cout << "Test Case 2: Insert at beginning\n";
  list.insertAtBeginning(5);
  list.display();  // Expected: 5  10  20  30
  cout << endl;

  // Test Case 3: Delete node (middle value) and display
  cout << "Test Case 3: Delete node 20\n";
  list.deleteNode(20);
  list.display();  // Expected: 5  10  30
  cout << endl;

  // Test Case 4: Delete at the beginning and display
  cout << "Test Case 4: Delete at beginning\n";
  list.deleteAtBeginning();
  list.display();  // Expected: 10  30
  cout << endl;

  // Test Case 5: Delete at the end and display
  cout << "Test Case 5: Delete at end\n";
  list.deleteAtEnd();
  list.display();  // Expected: 10
  cout << endl;

  // Test Case 6: Delete node that does not exist
  cout << "Test Case 6: Delete non-existing node\n";
  list.deleteNode(100);
  list.display();  // Expected: 10 (no change)
  cout << endl;

  // Test Case 7: Delete the last node
  cout << "Test Case 7: Delete last remaining node\n";
  list.deleteNode(10);
  list.display();  // Expected: (empty list)
  cout << endl;

  // Test Case 8: Search for a node
  cout << "Test Case 8: Search for node\n";
  cout << (list.search(30) ? "Found\n" : "Not Found\n");  // Expected: Not Found
  list.insertAtEnd(40);
  cout << (list.search(40) ? "Found\n" : "Not Found\n");  // Expected: Found
  cout << (list.search(50) ? "Found\n" : "Not Found\n");  // Expected: Not Found

  return 0;
}
