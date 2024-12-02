#include <bits/stdc++.h>
using namespace std;

// Brute force
int celebProb(int **mat, int n) {
  int *knowMe = new int[n];
  int *Iknow = new int[n];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (mat[i][j] == 1) {
        knowMe[j]++;
        Iknow[i]++;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (knowMe[i] == n - 1 && Iknow[i] == 0)
      return i;
  }

  return -1;
}

int celebrity(vector<vector<int> > &mat) {
  int n = mat.size();

  int top = 0;
  int down = n - 1;

  while (top < down) {
    if (mat[top][down] == 1)
      top++;
    else if (mat[down][top] == 1)
      down--;
    else {
      top++;
      down--;
    }
  }

  if (top > down) return -1;

  for (int i = 0; i < n; i++) {
    if (i == top) continue;
    if (mat[top][i] == 0 && mat[i][top] == 1)
      continue;
    else
      return -1;
  }

  return top;
}

int main() {
  int n;
  cin >> n;
  int **mat = nullptr;
  mat = new int *[n];
  for (int i = 0; i < n; i++)
    mat[i] = new int[n];

  return 0;
}

/*
Examples:

Input: mat[][] = [[0 1 0], [0 0 0], [0 1 0]]
Output: 1
Explanation: 0th and 2nd person both know 1. Therefore, 1 is the celebrity.
Input: mat[][] = [[0 1], [1 0]]
Output: -1
Explanation: The two people at the party both know each other. None of them is a celebrity.
Input: mat[][] = [[0]]
Output: 0
*/