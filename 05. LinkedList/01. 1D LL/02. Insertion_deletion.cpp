#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node {
 public:
  T data;
  Node<T> *next;

 public:
  Node(T val)
      : data(val), next(nullptr) {}
  Node(T val, Node<T> *nextNode)
      : data(val), next(nextNode) {}
};

template <typename T>
class LinkedList {
 public:
  Node<T> *head;

 public:
  LinkedList()
      : head(nullptr) {}

  void insertAtEnd(T val) {
    Node<T> *newNode = new Node<T>(val);
    if (head == nullptr) {
      head = newNode;
      return;
    }
    Node<T> *temp = head;
    while (temp->next != nullptr)
      temp = temp->next;
    temp->next = newNode;
  }

  void insertAtBeginning(T val) {
    Node<T> *newNode = new Node<T>(val);
    newNode->next = head;
    head = newNode;
  }

  void deleteNode(T val) {
    if (head == nullptr) return;
    if (head->data == val) {
      Node<T> *temp = head;
      head = head->next;
      delete temp;
      return;
    }
    Node<T> *temp = head;
    while (temp->next != nullptr && temp->next->data != val)
      temp = temp->next;
    if (temp->next == nullptr)
      return;
    Node<T> *toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
  }

  bool searchKey(T key) {
    if (head == NULL) return 0;
    if (head->data == key) return 1;
    Node<T> *temp = head;
    while (temp->next != NULL && temp->next->data != key)
      temp = temp->next;
    if (temp->next == NULL) return 0;
    return 1;
  }

  int length() {
    if (head == NULL) return 0;
    if (head->next == NULL) return 1;
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL) {
      cnt++;
      temp = temp->next;
    }
    return cnt;
  }

  void printList() {
    Node<T> *temp = head;
    while (temp != nullptr) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

int main() {
  LinkedList<int> L;
  L.insertAtEnd(1);
  L.insertAtEnd(2);
  L.insertAtEnd(3);
  L.insertAtBeginning(9);
  L.printList();

  return 0;
}