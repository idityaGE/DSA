#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr) {
  int n = arr.size();
  int profit = 0,min = arr[0], cost;
  for (int i = 0; i < n; i++) {
    if (arr[i] < min) min = arr[i];
    cost = arr[i] - min;
    profit = max(cost, profit);
  }
  return profit;
}

// 7 1 5 3 6 4
// profit = 5 [6 - 1]

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << maxProfit(arr) << endl;
  return 0;
}