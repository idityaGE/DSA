#include <bits/stdc++.h>
using namespace std;

vector<int> findNSE(vector<int>& arr, int n) {
  vector<int> nse(n);
  stack<int> st;
  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && arr[st.top()] >= arr[i]) {
      st.pop();
    }
    nse[i] = st.empty() ? n : st.top();
    st.push(i);
  }
  return nse;
}

vector<int> findPSE(vector<int>& arr, int n) {
  vector<int> pse(n);
  stack<int> st;
  for (int i = 0; i < n; i++) {
    while (!st.empty() && arr[st.top()] > arr[i]) {
      st.pop();
    }
    pse[i] = st.empty() ? -1 : st.top();
    st.push(i);
  }
  return pse;
}

vector<int> findNGE(vector<int>& arr, int n) {
  vector<int> nge(n);
  stack<int> st;
  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && arr[st.top()] < arr[i]) {
      st.pop();
    }
    nge[i] = st.empty() ? n : st.top();
    st.push(i);
  }
  return nge;
}

vector<int> findPGE(vector<int>& arr, int n) {
  vector<int> pge(n);
  stack<int> st;
  for (int i = 0; i < n; i++) {
    while (!st.empty() && arr[st.top()] <= arr[i]) {
      st.pop();
    }
    pge[i] = st.empty() ? -1 : st.top();
    st.push(i);
  }
  return pge;
}

long long sumSubarrayMax(vector<int>& arr, int n) {
  vector<int> nge = findNGE(arr, n);
  vector<int> pge = findPGE(arr, n);
  long long total = 0;
  for (int i = 0; i < n; i++) {
    int left = i - pge[i];
    int right = nge[i] - i;
    total += (long long)(left * right) * arr[i];
  }
  return total;
}

long long sumSubarrayMin(vector<int>& arr, int n) {
  vector<int> nse = findNSE(arr, n);
  vector<int> pse = findPSE(arr, n);
  long long total = 0;
  for (int i = 0; i < n; i++) {
    int left = i - pse[i];
    int right = nse[i] - i;
    total += (long long)(left * right) * arr[i];
  }
  return total;
}

long long subArrayRanges(vector<int>& arr) {
  int n = arr.size();
  return sumSubarrayMax(arr, n) - sumSubarrayMin(arr, n);
}

int main() {
  return 0;
}