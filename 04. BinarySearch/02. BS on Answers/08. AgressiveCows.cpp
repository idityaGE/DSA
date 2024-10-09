#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &stalls, int k, int mid) {
  int lastCow = stalls[0];
  int cow = 1;
  for (int i = 1; i < stalls.size(); i++) {
    int dist = stalls[i] - lastCow;
    if (dist >= mid) {
      cow++;
      lastCow = stalls[i];
    }
  }
  return cow >= k;
}

int aggressiveCows(vector<int> &stalls, int k) {
  sort(stalls.begin(), stalls.end());
  int n = stalls.size();
  int low = 1;
  int high = stalls[n - 1] - stalls[0];
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (isPossible(stalls, k, mid)) {
      low = mid + 1;  // you have to find maximum of minimum distance
    } else
      high = mid - 1;
  }
  return high;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << aggressiveCows(arr, 4);
  return 0;
}

/*
Sample Input 1 :
6 4
0 3 4 7 10 9

Sample Output 1 :
3

Explanation to Sample Input 1 :
The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions {0, 3, 7, 10}. Here distance between cows are 3, 4 and 3 respectively.
*/