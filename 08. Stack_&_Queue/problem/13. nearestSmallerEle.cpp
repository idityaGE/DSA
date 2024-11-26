#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> &A) {
  int n = A.size();
  vector<int> ans(n, -1);
  stack<int> st;

  for (int i = 0; i < n; i++) {
    while (!st.empty() && A[i] <= st.top())
      st.pop();
    if (!st.empty())
      ans[i] = st.top();
    st.push(A[i]);
  }
  return ans;
}

int main() {
  return 0;
}