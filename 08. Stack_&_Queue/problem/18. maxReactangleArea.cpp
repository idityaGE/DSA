#include <bits/stdc++.h>
using namespace std;

vector<int> findBoundary(vector<int>& arr, bool next) {
  int n = arr.size();
  vector<int> boundary(n);
  stack<int> st;

  int start = next ? n - 1 : 0;
  int end = next ? -1 : n;
  int step = next ? -1 : 1;

  for (int i = start; i != end; i += step) {
    while (!st.empty() && (next ? arr[st.top()] >= arr[i]
                                : arr[st.top()] > arr[i]))
      st.pop();

    boundary[i] = st.empty() ? (next ? n : -1) : st.top();
    st.push(i);
  }

  return boundary;
}

int largestRectangleArea(vector<int>& heights) {
  vector<int> nse = findBoundary(heights, true);
  vector<int> pse = findBoundary(heights, false);

  int maxArea = 0;

  for (int i = 0; i < heights.size(); i++) {
    int width = nse[i] - pse[i] - 1;
    int area = heights[i] * width;
    maxArea = max(maxArea, area);
  }

  return maxArea;
}

int main() {
  return 0;
}

/*
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
*/