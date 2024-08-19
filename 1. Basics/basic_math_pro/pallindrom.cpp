#include <bits/stdc++.h>
using namespace std;

bool isPallindrom(int n) {
  int rev = 0;
  int num = n;
  int rem;
  while (num) {
    rem = num % 10;
    num /= 10;
    rev = rev * 10 + rem;
  }
  return rev == n;
}

int main() {
  int n;
  cin >> n;
  cout << isPallindrom(n);
  return 0;
}