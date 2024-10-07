#include <bits/stdc++.h>
using namespace std;

long long hoursNeeded(vector<int> arr, int hourly) {
  long long totalH = 0;
  for (int i = 0; i < arr.size(); i++)
    totalH += ceil((double)arr[i] / (double)hourly);
  return totalH;
}

int minimumRateToEatBananas(vector<int> arr, int h) {
  int low = 1;
  int high = *max_element(arr.begin(), arr.end());
  while (low <= high) {
    int mid = (low + high) / 2;
    if (hoursNeeded(arr, mid) <= h)
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
  cout << minimumRateToEatBananas(arr, 5);
  return 0;
}

/*
Sample Input 1:
4
7 15 6 3
8

Sample Output 1:
5

Explanation Of Sample Input 1:
Input: ‘n’ = 4, ‘a’ = [7, 15, 6, 3], ‘h’ = 8

Output: 5

Explanation: If ‘m’ = 5, then
The time taken to empty the 1st pile is 2 hour.
The time taken to empty the 2nd pile is 3 hour.
The time taken to empty the 3rd pile is 2 hour.
The time taken to empty the 4th pile is 1 hour.
Therefore a total of 8 hours is taken. It can be shown that if the rate of eating bananas is reduced, they can’t be eaten in 8 hours.


Sample Input 2:
5
25 12 8 14 19
5

Sample Output 2:
25

Explanation Of Sample Input 2:
Input: ‘n’ = 5, ‘a’ = [25,12,8,14,19], ‘h’ = 5

Output: 25

Explanation: If ‘m’ = 25,
The time taken to empty the 1st pile is 1 hour.
The time taken to empty the 2nd pile is 1 hour.
The time taken to empty the 3rd pile is 1 hour.
The time taken to empty the 4th pile is 1 hour.
The time taken to empty the 5th pile is 1 hour.
Therefore a total of 5 hours is taken. It can be shown that if the rate of eating bananas is reduced, they can’t be eaten in 5 hours.
*/