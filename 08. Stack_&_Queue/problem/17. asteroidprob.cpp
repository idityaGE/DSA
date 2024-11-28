#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
  stack<int> st;

  for (auto a : asteroids) {
    if (a > 0)
      st.push(a);
    else {
      while (!st.empty() && st.top() > 0 && st.top() < abs(a))
        st.pop();

      if (st.empty() || st.top() < 0)
        st.push(a);

      if (!st.empty() && st.top() == abs(a))
        st.pop();
    }
  }

  vector<int> ans(st.size());
  int i = st.size() - 1;

  while (!st.empty()) {
    ans[i--] = st.top();
    st.pop();
  }

  return ans;
}

int main() {
  return 0;
}

/*
Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
*/