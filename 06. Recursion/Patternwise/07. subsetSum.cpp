#include <bits/stdc++.h>
using namespace std;

void subsetSum(vector<int> &arr, vector<int> &sumArr, int sum = 0, int index = 0) {
  if (index == arr.size()) {
    sumArr.push_back(sum);
    return;
  }

  // pick
  subsetSum(arr, sumArr, sum + arr[index], index + 1);

  // do not pick
  subsetSum(arr, sumArr, sum, index + 1);
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  vector<int> sumArr;
  subsetSum(arr, sumArr);

  sort(sumArr.begin(), sumArr.end());

  for (auto i : sumArr)
    cout << i << ' ';

  return 0;
}

/*
Input: n = 2, arr[] = {2, 3}
Output: 0 2 3 5
Explanation: When no elements is taken then Sum = 0. When only 2 is taken then Sum = 2. When only 3 is taken then Sum = 3. When element 2 and 3 are taken then Sum = 2+3 = 5.
*/