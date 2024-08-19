#include <bits/stdc++.h>
using namespace std;

bool isArmstrong(int n) {
  int cnt = (int)(log10(n) + 1);
  int ans = 0;
  int num = n;
  int rem;
  while (num) {
    rem = num % 10;
    ans += pow(rem , cnt);
    num /= 10;
  }
  return ans == n;
}

int main() {
  int n;
  cin >> n;
  cout << isArmstrong(n);
  return 0;
}