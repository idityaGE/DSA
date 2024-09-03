#include <bits/stdc++.h>
using namespace std;

struct NODE {
  int data;
  int *next;
};

NODE *create(NODE *p, int data) {
  p = new NODE;
  p->data = data;
  p->next = nullptr;
  return p;
}

NODE *insert(NODE *p, int data, int pos) {
  if (p == nullptr) {
    p = create(p, data);
  } else {
    NODE *temp;
    temp = p;
    for (int i = 0; i < pos; i++) {
      if (temp->next != nullptr)
        temp = temp->next;
      else {
        cout << "wrong position" << endl;
        delete temp;
        return p;
      }
    }
    temp->next = create(temp->next, data);
  }
  return p;
}

NODE *delete_pos(NODE *p, int pos) {
  if (p == nullptr)
    cout << "Link List is empty" << endl;
  else {
    NODE *temp;
    temp = p;
    for (int i = 0; i < pos; i++) {
      if (temp->next != nullptr)
        temp = temp->next;
      else {
        cout << "wrong position" << endl;
        delete temp;
        return p;
      }
      NODE *temp1;
      temp1 = temp->next;
      temp->next = temp->next->next;
      delete temp1;
    }
  }
  return p;
}

NODE *sort(NODE *p) {
  if (p == nullptr)
    cout << "Link List is empty" << endl;
  else {
    NODE *temp1, temp2;
    temp1 = p;
    while (temp1 != nullptr)
      temp2 = temp1->next;
    while (temp2 != nullptr) {
      if (temp1->data > temp2.data)
        swap(temp1->data, temp2.data);
      temp2 = temp2.next;
    }
    temp1 = temp1->next;
  }
  return p;
}

void dis_rev(NODE *p) {
  if (p == nullptr)
    cout << "Link List is empty" << endl;
  else {
    while (p != nullptr)
      dis_rev(p->next);
    cout << p->data << endl;
  }
}

NODE *merge_sort(NODE *p1, NODE *p2) {
  if (p1 == nullptr && p2 == nullptr)
    cout << "Both of them is empty" << endl;
  else if (p1 == nullptr)
    return p2;
  else if (p2 == nullptr)
    return p1;
  else {
    NODE *temp;
    temp = p1;
    while (temp != nullptr)
      temp = temp->next;
    temp = p2;
    p1 = sort(p1);
    return p1;
  }
}

int mid(NODE *p) {
  if (p == nullptr)
    cout << "Link List is empty" << endl;
  else {
    NODE *fast, *slow;
    fast = p;
    slow = p;
    while (fast != nullptr || fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow->data;
  }
}

NODE *reverse(NODE *p) {
  if (p == nullptr)
    cout << "Link List is empty" << endl;
  else if (p->next == nullptr)
    cout << "ll has only one elem" << endl;
  else {
    NODE *prev, *curr, *fut;
    prev = nullptr;
    curr = p;
    fut = p->next;
    while (fut != nullptr) {
      curr->next = prev;
      prev = curr;
      curr = fut;
      fut = fut->next;
    }
    curr->next = prev;
    p = curr;
  }
  return p;
}

NODE *remove_dupl_sorted(NODE *p) {
  if (p == nullptr)
    cout << "Link List is empty" << endl;
  else if (p->next == nullptr)
    cout << "ll has only one elem" << endl;
  else {
    NODE *temp = p;
    NODE *temp1;
    while (temp != nullptr) {
      if (temp->data == temp->next->data) {
        temp1 = temp->next;
        temp->next = temp->next->next;
        delete temp1;
      } else
        temp = temp->next;
    }
  }
  return p;
}

int main() {
  return 0;
}