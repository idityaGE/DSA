#include <bits/stdc++.h>
using namespace std;

pair<int, int> repeating_and_missing(vector<int> &arr) {
  int n = arr.size();
  vector<int> vc(n + 1);
  for (int i = 0; i < n; i++)
    vc[arr[i]]++;
  pair<int, int> pp;
  for (int i = 0; i <= n; i++) {
    if (vc[i] == 2) pp.first = i;
    if (vc[i] == 0) pp.second = i;
  }
  return pp;
}

pair<int, int> findMissingRepeatingNumbers(vector<int>& arr) {
  long long n = arr.size();
  // s - sn
  // s2 - s2n
  long long sn = (n * (n + 1)) / 2;
  long long s2n = (n * (n + 1) * (2 * n + 1)) / 6;
  long long s = 0, s2 = 0;
  for (int i = 0; i < n; i++) {
    s += arr[i];
    s2 += ((long long)arr[i] * (long long)arr[i]);
  }
  long long val1 = s - sn;
  long long val2 = s2 - s2n;
  val2 = val2 / val1;
  long long rep = (val1 + val2) / 2;
  long long mis = rep - val1;
  return {(int)rep, (int)mis};
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  pair<int, int> pp = findMissingRepeatingNumbers(arr);
  cout << pp.first << " " << pp.second << endl;
  return 0;
}