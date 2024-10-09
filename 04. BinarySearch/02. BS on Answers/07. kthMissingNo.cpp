#include <bits/stdc++.h>
using namespace std;

// Brute force
int kthMissingNo(vector<int> arr, int k) {
  int missingNo = k;
  for (int i = 0; i < arr.size(); i++)
    if (arr[i] <= missingNo)
      missingNo++;
    else
      return missingNo;
}

// optimal approch
int missingK(vector<int> arr, int k) {
  int n = arr.size();
  int low = 0;
  int high = n - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    int missing = arr[mid] - (mid + 1);
    if (missing < k)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return k + low;
}

/*
 0 1 2 3 4
 2 3 4 7 11          k = 5

    4 - (mid+1) = 1 < k --> low = mid + 1
    7 - (mid+1) = 3 < k --> low = mid + 1
    11- (mid+1) = 6 > k --> high = mid - 1

    high > low --> break;
    high = 3
    low  = 4

    missing = arr[high] + more
            = arr[high] + k - (arr[high] - (high + 1))
            = arr[high] + k - arr[high] + high + 1
            = k + high + 1
            = k + low
*/

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << missingK(arr, 5);
  return 0;
}

/*
Sample Input 1 :
4
4 7 9 10
1

Sample Output 1 :
1

Explanation For Sample Input 1 :
The missing numbers are 1, 2, 3, 5, 6, 8, 11, 12, ……, and so on.
Since 'k' is 1, the first missing element is 1.
*/