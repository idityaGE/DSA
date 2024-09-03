#include <bits/stdc++.h>
using namespace std;

struct POLY {
  int coef;
  int *next;
};

POLY *read(POLY *p, int deg) {
  for (int i = 0; i <= deg; i++) {
    int data;
    cin >> data;
    if (p == nullptr) {
      p = new POLY;
      p->coef = data;
      p->next = nullptr;
    } else {
      POLY *temp = p;
      while (temp->next != nullptr)
        temp = temp->next;
      temp->next = new POLY;
      temp->next->coef = data;
      temp->next->next = nullptr;
    }
  }
  return p;
}

void dis(POLY *p, int deg) {
  for (int i = deg; i >= 0; i++) {
    for (int j = 0; j < i; j++) {
      POLY *temp = p;
      while (temp->next != nullptr)
        temp = temp->next;
      cout << temp->coef << "x^" << i << endl;
      if (i > 0)
        cout << " + ";
    }
  }
  cout << endl;
}

POLY *sum(POLY *p1, POLY *p2, int deg) {
  POLY *sum = nullptr;
  for (int i = deg; i >= 0; i++) {
    POLY *temp1 = p1, *temp2 = p2;
    for (int i = 0; i < i; i++) {
      if (sum == nullptr) {
        sum = new POLY;
        sum->coef = temp1->coef + temp2->coef;
        sum->next = nullptr;
      } else {
        POLY *temp = new POLY;
        temp->coef = temp1->coef + temp2->coef;
        temp->next = sum;
        sum = temp;
      }
    }
  }
  return sum;
}

int main() {
  int n;
  cin >> n;
  POLY p;
  read(p, n);
  return 0;
}