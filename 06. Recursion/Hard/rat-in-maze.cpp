#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &mat, vector<vector<int>> &visit, vector<string> &ans, string move = "", int i = 0, int j = 0) {
  if (i == mat.size() - 1 && j == mat.size() - 1) {
    ans.push_back(move);
    return;
  }
  // downward
  if (i + 1 < mat.size() && !visit[i + 1][j] && mat[i + 1][j] == 1) {
    visit[i][j] = 1;
    solve(mat, visit, ans, move + 'D', i + 1, j);
    visit[i][j] = 0;
  }

  // left
  if (j - 1 >= 0 && !visit[i][j - 1] && mat[i][j - 1] == 1) {
    visit[i][j] = 1;
    solve(mat, visit, ans, move + 'L', i, j - 1);
    visit[i][j] = 0;
  }

  // right
  if (j + 1 < mat.size() && !visit[i][j + 1] && mat[i][j + 1] == 1) {
    visit[i][j] = 1;
    solve(mat, visit, ans, move + 'R', i, j + 1);
    visit[i][j] = 0;
  }

  // upward
  if (i - 1 >= 0 && !visit[i - 1][j] && mat[i - 1][j] == 1) {
    visit[i][j] = 1;
    solve(mat, visit, ans, move + 'U', i - 1, j);
    visit[i][j] = 0;
  }
}

vector<string> findPath(vector<vector<int>> &mat) {
  int n = mat.size();
  vector<string> ans;
  vector<vector<int>> visit(n, vector<int>(n, 0));
  if (mat[0][0] == 1) solve(mat, visit, ans);
  return ans;
}

// better approch
void solve(vector<vector<int>> &mat, vector<vector<int>> &visit, vector<string> &ans, int di[], int dj[], string move = "", int i = 0, int j = 0) {
  // Base case: If we have reached the destination, add the path and return
  if (i == mat.size() - 1 && j == mat.size() - 1) {
    ans.push_back(move);
    return;
  }

  string dir = "DLRU";
  for (int ind = 0; ind < 4; ind++) {
    int nexti = i + di[ind];
    int nextj = j + dj[ind];

    // Check if the next position is within bounds, not visited, and is traversable (mat[nexti][nextj] == 1)
    if (nexti >= 0 && nextj >= 0 && nexti < mat.size() && nextj < mat.size() && !visit[nexti][nextj] && mat[nexti][nextj] == 1) {
      visit[nexti][nextj] = 1;                                        // Mark as visited
      solve(mat, visit, ans, di, dj, move + dir[ind], nexti, nextj);  // Recurse with the new path
      visit[nexti][nextj] = 0;                                        // Backtrack, unmark as visited
    }
  }
}

vector<string> findPath(vector<vector<int>> &mat) {
  int n = mat.size();
  vector<string> ans;

  // If the starting point is blocked, return an empty result immediately
  if (mat[0][0] == 0) return ans;

  vector<vector<int>> visit(n, vector<int>(n, 0));  // Visit matrix to track visited cells

  // Movement combinations (down, left, right, up)
  int di[] = {+1, 0, 0, -1};
  int dj[] = {0, -1, 1, 0};

  // Start solving if the start point is valid
  visit[0][0] = 1;                 // Mark the start cell as visited
  solve(mat, visit, ans, di, dj);  // Call the recursive function
  return ans;
}

int main() {
  return 0;
}

/*
Input: mat[][] = [[1, 0, 0, 0],
                  [1, 1, 0, 1],
                  [1, 1, 0, 0],
                  [0, 1, 1, 1]]
Output: DDRDRR DRDDRR
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
*/