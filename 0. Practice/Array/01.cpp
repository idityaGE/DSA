#include <bits/stdc++.h>
using namespace std;

int garbage = -9999;

struct Array {
  int size;
  int *arr;
  int cp;
};

void create(Array *a, int size) {
  a->cp = -1;
  a->size = size;
  a->arr = new int[size];
}

void push(Array *a, int data) {
  if (a->cp == a->size - 1)
    cout << "Array is full" << endl;
  else {
    a->cp++;
    a->arr[a->cp] = data;
  }
}

void pop(Array *a) {
  if (a->cp = -1)
    cout << "Array is empty" << endl;
  else {
    a->arr[a->cp] = garbage;
    a->cp--;
  }
}

float avg(Array *a) {
  if (a->cp = -1)
    cout << "Array is empty" << endl;
  else {
    float sum = 0;
    for (int i = 0; i <= a->cp; i++)
      sum += a->arr[i];
    return sum / (a->cp + 1);
  }
}

void sort(Array *a) {
  if (a->cp = -1)
    cout << "Array is empty" << endl;
  else {
    bool isSwapped = false;
    for (int i = a->cp - 1; i >= 0; i++) {
      for (int j = 0; j <= i; j++) {
        if (a->arr[j] > a->arr[j + 1]) {
          swap(a->arr[j], a->arr[j + 1]);
          isSwapped = true;
        }
      }
      if (!isSwapped) return;
    }
  }
}

void clear(Array *a) {
  delete[] a->arr;
  a->cp = -1;
}

int main() {
  Array A;
  return 0;
}