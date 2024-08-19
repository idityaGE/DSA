#include <bits/stdc++.h>
using namespace std;

int count(int n) {
  int cnt = 0;
  while (n) {
    n /= 10;
    cnt++;
  }
  return cnt;
}

int cnt_log(int n) {
  return (int)log10(n) + 1;
}

// time complexity is O(log10(n))

int main() {
  int n;
  cin >> n;
  cout << cnt_log(n) << endl;
  return 0;
}