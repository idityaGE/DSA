#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>>& board, int row, int col, char c) {
  for (int i = 0; i < 9; i++) {
    if (board[i][col] == c)
      return 0;
    if (board[row][i] == c)
      return 0;
    if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
      return 0;
  }
  return 1;
}

bool solve(vector<vector<char>>& board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {
      if (board[i][j] == '.') {
        for (char c = '1'; c <= '9'; c++) {
          if (isValid(board, i, j, c)) {
            board[i][j] = c;
            if (solve(board) == 1)
              return 1;
            else
              board[i][j] = '.';
          }
        }
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  vector<vector<char>> board;
  board.resize(9, vector<char>(9));
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {
      cin >> board[i][j];
    }
  }

  solve(board);

  for (auto i : board) {
    for (auto j : i)
      cout << j << "  ";
    cout << endl;
  }

  return 0;
}

/*
Input : 
5 3 . . 7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
8 . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9

Output:
5  3  4  6  7  8  9  1  2  
6  7  2  1  9  5  3  4  8  
1  9  8  3  4  2  5  6  7  
8  5  9  7  6  1  4  2  3  
4  2  6  8  5  3  7  9  1  
7  1  3  9  2  4  8  5  6  
9  6  1  5  3  7  2  8  4  
2  8  7  4  1  9  6  3  5  
3  4  5  2  8  6  1  7  9  

*/