#include <bits/stdc++.h>
using namespace std;

bool isShiped(vector<int> &arr, int capacity, int day) {
  int n = arr.size();
  int cntDays = 1;
  int sumOfWeights = 0;
  for (int i = 0; i < n; i++) {
    sumOfWeights += arr[i];
    if (sumOfWeights > capacity) {
      cntDays++;
      sumOfWeights = arr[i];
    }
  }
  return cntDays <= day;
}

int leastWeightCapacity(vector<int> &arr, int d) {
  int low = *max_element(arr.begin(), arr.end());
  int high = accumulate(arr.begin(), arr.end(), 0);  // sum of all ele in arr
  while (low <= high) {
    int mid = (low + high) / 2;
    if (isShiped(arr, mid, d))
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
  cout << leastWeightCapacity(arr, 5);
  return 0;
}

/*
Sample Input 1:
8 5
5 4 5 2 3 4 5 6
Sample Output 1:
9
Explanation for Sample Input 1:
In the test case, the given weights are [5,4,5,2,3,4,5,6] and these are needed to be shipped in 5 days. We can divide these weights in the following manner:
Day         Weights            Total
1        -   5, 4          -    9
2        -   5, 2          -    7
3        -   3, 4          -    7
4        -   5             -    5
5        -   6             -    6
The least weight capacity needed is 9, which is the total amount of weight that needs to be taken on Day 1.
*/