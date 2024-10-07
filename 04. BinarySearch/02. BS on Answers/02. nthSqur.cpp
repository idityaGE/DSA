#include <bits/stdc++.h>
using namespace std;

/*
Sample Input 1:
3 27

Sample Output 1:
3

Explanation For Sample Input 1:
3rd Root of 27 is 3, as (3)^3 equals 27.
*/

int findNthSqur(int n, int m) {
  int low = 1, high = m;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    double res = pow(mid, n);
    if (res == m)
      return mid;
    else if (res > m)
      high = mid - 1;
    else
      low = mid + 1;
  }
  return -1;
}

int main() {
  int n, m;
  cin >> n >> m;

  cout << findNthSqur(n, m);
  return 0;
}