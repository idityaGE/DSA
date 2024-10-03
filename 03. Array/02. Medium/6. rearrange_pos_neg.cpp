#include <bits/stdc++.h>
using namespace std;

// vareity 1 => where +ve and -ve elem are prasent in equal no.
void rearrangeArray(vector<int>& arr) {
  int n = arr.size();
  vector<int> ans(n, 0);
  int posIdx = 0, negIdx = 1;
  for (int i = 0; i < n; i++) {
    if (arr[i] < 0) {
      ans[negIdx] = arr[i];
      negIdx += 2;
    } else {
      ans[posIdx] = arr[i];
      posIdx += 2;
    }
  }
  for(auto i : ans)
    cout << i << " ";
}
// i/p = 7 1 -5 3 -6 -4
// o/p = 7 -5 1 -6 3 -4 


// vareity 2 => where +ve and -ve elem are not prasent in equal no.
void alternateNumbers(vector<int> &a) {
  vector<int> pos, neg;
  int n = a.size();
  for (int i = 0; i < n; i++) {
    if (a[i] < 0)
      neg.push_back(a[i]);
    else
      pos.push_back(a[i]);
  }
  if (pos.size() > neg.size()) {
    for (int i = 0; i < neg.size(); i++) {
      a[2 * i] = pos[i];
      a[2 * i + 1] = neg[i];
    }
    int idx = neg.size() * 2;
    for (int i = neg.size(); i < pos.size(); i++) {
      a[idx] = pos[i];
    }
  } else {
      for (int i = 0; i < pos.size(); i++) {
      a[2 * i] = pos[i];
      a[2 * i + 1] = neg[i];
    }
    int idx = pos.size() * 2;
    for (int i = pos.size(); i < neg.size(); i++) {
      a[idx] = neg[i];
    }
  }
  for(auto i: a)
    cout << i << " ";
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  rearrangeArray(arr);
  return 0;
}