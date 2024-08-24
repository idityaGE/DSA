#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int remove_duplicate(int arr[], int n) {
  // using set
  // set<int> st;
  // for (int i = 0; i < n; i++)
  //   st.insert(arr[i]);
  // int i = 0;
  // for (auto it : st)
  //   arr[i] = it;
  // return st.size();

  // using two pointer
  int cp = 0;
  for (int i = 1; i < n; i++) {
    if (arr[cp] != arr[i]) {
      cp++;
      arr[cp] = arr[i];
    }
  }
  return cp + 1;
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  int N = remove_duplicate(arr, n);
  print(arr, N);
  return 0;
}