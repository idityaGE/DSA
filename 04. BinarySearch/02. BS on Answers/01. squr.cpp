#include <bits/stdc++.h>
using namespace std;

/*
Sample Input 1:
6
Sample Output 1:
2
Explanation of Sample Input 1:
The square root of the given number 6 lies between 2 and 3, so the floor value is 2.
*/

int findSqur(int n) {
  int low = 0, high = n;
  while (low <= high) {
    long long mid = (low + high) / 2;
    long long val = (mid * mid);
    if (val <= n)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return high;
}

int main() {
  int n;
  cin >> n;

  cout << findSqur(n);
  return 0;
}