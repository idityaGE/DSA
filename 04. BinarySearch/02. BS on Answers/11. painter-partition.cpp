#include <bits/stdc++.h>
using namespace std;

bool timeReq(vector<int> arr, int k, int maxtime) {
  int time = arr[0];
  int painter = 1;
  for (int i = 1; i < arr.size(); i++) {
    time += arr[i];
    if (time > maxtime) {
      painter++;
      time = arr[i];
    }
  }
  return k >= painter;
}

int findLargestMinDistance(vector<int> &arr, int k) {
  int n = arr.size();
  if (k > n)
    return -1;
  int low = *max_element(arr.begin(), arr.end());
  int high = accumulate(arr.begin(), arr.end(), 0);
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (timeReq(arr, k, mid))
      high = mid - 1;
    else
      low = mid + 1;
  }
  return low;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << findLargestMinDistance(arr, 2);

  return 0;
}

/*
Sample Input 1 :
4 2
10 20 30 40

Sample Output 1 :
60

Explanation For Sample Input 1 :
In this test case, we can divide the first 3 boards for one painter and the last board for the second painter.


Sample Input 2 :
2 2
48 90

Sample Output 2 :
90
*/