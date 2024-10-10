#include <bits/stdc++.h>
using namespace std;

bool isSplitPossible(vector<int> arr, int k, int maxTime) {
  int sum = arr[0];
  int cnt = 1;
  for (int i = 1; i < arr.size(); i++) {
    sum += arr[i];
    if (sum > maxTime) {
      cnt++;
      sum = arr[i];
    }
  }
  return cnt <= k;
}

int splitArray(vector<int>& arr, int k) {
  int n = arr.size();
  if (k > n)
    return -1;
  int low = *max_element(arr.begin(), arr.end());
  int high = accumulate(arr.begin(), arr.end(), 0);
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (isSplitPossible(arr, k, mid))
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

  cout << splitArray(arr, 2);

  return 0;
}

/*
Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
*/