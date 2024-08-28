#include <bits/stdc++.h>
using namespace std;

bool read(vector<int> &arr, int n, int target) {
  // Brute Force [TC => O(n^2)]
  // for(int i = 0; i < n; i++){
  //     for (int j = i; j < n; j++){
  //         if(arr[i] + arr[j] == target){
  //             return true;
  //         }
  //     }
  // }
  // return false;

  // Hasging  [TC => O(n lon n)] [SC => O(n)]
  //   map<int, int> mp;
  //   for (int i = 0; i < n; i++) {
  //     int rem = target - arr[i];
  //     if (mp.find(rem) != mp.end())
  //       return true;
  //     mp[arr[i]] = i;
  //   }
  //   return false;

  // Two pointer [TC => O(n lon n)] [SC => O(n)]
  sort(arr.begin(), arr.end());
  int low = 0;
  int high = n - 1;
  while (low < high) {
    if (arr[low] + arr[high] == target) {
      return true;
    } else if (arr[low] + arr[high] < target) {
      low++;
    } else {
      high--;
    }
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int k;
  cin >> k;

  cout << (read(arr, n, k) ? "YES" : "NO") << endl;

  return 0;
}