#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  string url;
  Node *next;
  Node *back;

  Node(string val)
      : url(val), next(nullptr) {}
  Node(string val, Node *nextNode)
      : url(val), next(nextNode) {}
  Node(string val, Node *nextNode, Node *randomNode)
      : url(val), next(nextNode), back(randomNode) {}
};

class Browser {
  Node *currentTab;

 public:
  Browser(string &homepage) {
    currentTab = new Node(homepage);
  }

  void visit(string &url) {
    Node *newCurrTab = new Node(url);
    currentTab->next = newCurrTab;
    newCurrTab->back = currentTab;
    currentTab = newCurrTab;
  }

  string back(int steps) {
    while (steps) {
      if (currentTab->back)
        currentTab = currentTab->back;
      else
        break;
      steps--;
    }
    return currentTab->url;
  }

  string forward(int steps) {
    while (steps) {
      if (currentTab->next)
        currentTab = currentTab->next;
      else
        break;
      steps--;
    }
    return currentTab->url;
  }
};

int main() {
  vector<int> arr = {1, 3, 5, 2, 6};
  cout << endl;
  return 0;
}