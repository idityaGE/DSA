#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int>& arr, int day, int m, int k) {
  int n = arr.size();
  int noOfBooke = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] <= day)
      cnt++;
    else {
      noOfBooke += (cnt / k);
      cnt = 0;
    }
  }
  noOfBooke += (cnt / k);
  return noOfBooke >= m;
}

int minDays(vector<int>& arr, int m, int k) {
  // m - mini no of Booke
  // k - no of consecutive flower requried
  int n = arr.size();
  long long val = m * 1ll * k * 1ll;
  if (val > n)
    return -1;  // impossible case.

  int low = *min_element(arr.begin(), arr.end());
  int high = *max_element(arr.begin(), arr.end());
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (possible(arr, mid, m, k))
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

  cout << minDays(arr, 3, 2);
  return 0;
}

/*
Sample Input 1 :
9
1 2 1 2 7 2 2 3 1
3 2
Sample Output 1 :
3
Explanation For Sample Input 1 :
We will return 3, because:
All the roses with 'arr[i]' less than equal to 3 have already bloomed after 3 days, this means every rose except the 5th rose has bloomed. Now we can form the first bouquet from the first three roses and the second bouquet from the last three roses.
*/