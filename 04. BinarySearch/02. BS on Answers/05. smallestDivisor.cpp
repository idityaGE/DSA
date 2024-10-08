#include <bits/stdc++.h>
using namespace std;

bool sumOfdivisor(vector<int> arr, int divisor, int limit) {
  int n = arr.size();
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += (arr[i] / divisor);
    if (arr[i] % divisor)  // making ciel
      sum++;
  }
  return sum <= limit;
}

int smallestDivisor(vector<int> &arr, int limit) {
  int low = 1;
  int high = *max_element(arr.begin(), arr.end());
  while (low <= high) {
    int mid = (low + high) / 2;
    if (sumOfdivisor(arr, mid, limit))
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

  cout << smallestDivisor(arr, 8);
  return 0;
}

/*
Sample Input 1 :
5
1 2 3 4 5
8
Sample Output 1 :
3
Explanation for Sample Input 1 :
We can get a sum of 15(1 + 2 + 3 + 4 + 5) if we choose 1 as a divisor.
The sum is 9(1 + 1 + 2 + 2 + 3)  if we choose 2 as a divisor, and the sum is 7(1 + 1 + 1 + 2 + 2) if we choose 3 as a divisor, which is less than the 'limit'.
Hence we return 3.
*/