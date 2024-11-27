#include <bits/stdc++.h>
using namespace std;

vector<int> findNSE(vector<int> arr) {
  int n = arr.size();
  vector<int> nse(n);
  stack<int> st;
  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && arr[st.top()] >= arr[i])
      st.pop();
    nse[i] = st.empty() ? n : st.top();
    st.push(i);
  }
  return nse;
}

vector<int> findPSE(vector<int> arr) {
  int n = arr.size();
  vector<int> pse(n);
  stack<int> st;
  for (int i = 0; i < n; i++) {
    while (!st.empty() && arr[st.top()] > arr[i])
      st.pop();
    pse[i] = st.empty() ? -1 : st.top();
    st.push(i);
  }
  return pse;
}

int sumSubarrayMins(vector<int>& arr) {
  vector<int> nse = findNSE(arr);
  vector<int> pse = findPSE(arr);

  int total = 0, mod = (int)(1e9 + 7);

  for (int i = 0; i < arr.size(); i++) {
    int left = i - pse[i];
    int right = nse[i] - i;

    // modulo to ensure the result doesn't overflow.
    total = (total + (right * left * (long long)arr[i]) % mod) % mod;
  }
  return total;
}

int main() {
  return 0;
}

/*
Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444
*/