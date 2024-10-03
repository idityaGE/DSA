#include <bits/stdc++.h>
using namespace std;

int reverse(int n) {
  int rev = 0;
  int rem;
  while (n) {
    rem = n % 10;
    n /= 10;
    rev = rev * 10 + rem;
  }
  return rev;
}

int main() {
  int n;
  cin >> n;
  cout << reverse(n);
  return 0;
}