#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int> > arr) {
  for (auto i : arr) {
    for (auto j : i)
      cout << j << "  ";
    cout << endl;
  }
}

int sum(vector<int> arr) {
  int sum = 0;
  for (auto i : arr)
    sum += i;
  return sum;
}

// method 1
void subsequenceSumK(vector<vector<int> > &res, vector<int> &subset, vector<int> &arr, int k, int index = 0) {
  if (index == arr.size()) {
    if (k == sum(subset))
      res.push_back(subset);
    return;
  }
  // pick
  subset.push_back(arr[index]);
  subsequenceSumK(res, subset, arr, k, index + 1);

  // not pick
  subset.pop_back();
  subsequenceSumK(res, subset, arr, k, index + 1);
}

// method 2
void printS(int ind, vector<int> &subset, int s, int sum, vector<int> &arr) {
  if (ind == arr.size()) {
    if (s == sum) {
      for (auto i : subset) cout << i << "  ";
      cout << endl;
    }
    return;
  }
  // pick
  subset.push_back(arr[ind]);
  s += arr[ind];
  printS(ind + 1, subset, s, sum, arr);

  subset.pop_back();
  s -= arr[ind];

  // not pick
  printS(ind + 1, subset, s, sum, arr);
}

// print only one sum of K
// to achive this we will make the function a bool and it will return if the contion is satisfied or not
bool printS_one(int ind, vector<int> &subset, int s, int sum, vector<int> &arr) {
  if (ind == arr.size()) {
    if (s == sum) {
      for (auto i : subset) cout << i << "  ";
      cout << endl;
      return true;
    } else
      return false;
  }
  // pick
  subset.push_back(arr[ind]);
  s += arr[ind];
  if (printS_one(ind + 1, subset, s, sum, arr) == true) return true;

  subset.pop_back();
  s -= arr[ind];

  // not pick
  if (printS_one(ind + 1, subset, s, sum, arr) == true) return true;

  return false;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  vector<vector<int> > res;
  vector<int> subset;
  // subsequenceSumK(res, subset, arr, 2);
  printS_one(0, subset, 0, 2, arr);

  // print(res);
  return 0;
}