#include <bits/stdc++.h>
using namespace std;

bool safe(int row, int col, vector<string>& board) {
  int dup_row = row;
  int dup_col = col;

  while (row >= 0 && col >= 0) {
    if (board[row][col] == 'Q')
      return false;
    row--, col--;
  }

  row = dup_row;
  col = dup_col;

  while (col >= 0) {
    if (board[row][col] == 'Q')
      return false;
    col--;
  }

  col = dup_col;

  while (row < board.size() && col >= 0) {
    if (board[row][col] == 'Q')
      return false;
    row++, col--;
  }

  return true;
}

void solve(vector<vector<string>>& ans, vector<string>& board, int col = 0) {
  if (col == board.size()) {
    ans.push_back(board);
    return;
  }

  for (int row = 0; row < board.size(); row++) {
    if (safe(row, col, board)) {
      board[row][col] = 'Q';
      solve(ans, board, col + 1);
      board[row][col] = '.';
    }
  }
}

void printChessBoard(const vector<string>& board) {
  for (const auto& row : board) {
    for (char cell : row) {
      if (cell == 'Q')
        cout << "♛ ";
      else
        cout << "⬜ ";
    }
    cout << endl;
  }
}

// better
void solve_hash(vector<vector<string>>& ans, vector<string>& board,
                vector<int> leftRow, vector<int> lowerDia, vector<int> upperDia,
                int col = 0) {
  if (col == board.size()) {
    ans.push_back(board);
    return;
  }

  for (int row = 0; row < board.size(); row++) {
    if (leftRow[row] == 0 && lowerDia[col + row] == 0 &&
        upperDia[board.size() - 1 + col - row] == 0) {
      leftRow[row] = 1;
      lowerDia[col + row] = 1;
      upperDia[board.size() - 1 + col - row] = 1;

      board[row][col] = 'Q';
      solve_hash(ans, board, leftRow, lowerDia, upperDia, col + 1);
      board[row][col] = '.';

      leftRow[row] = 0;
      lowerDia[col + row] = 0;
      upperDia[board.size() - 1 + col - row] = 0;
    }
  }
}

vector<vector<string>> solveNQueens_hash(int n) {
  vector<vector<string>> ans;
  vector<string> board(n);
  string s(n, '.');
  for (int i = 0; i < n; i++)
    board[i] = s;
  // hashing
  vector<int> leftRow(n, 0);
  vector<int> lowerDia((2 * n - 1), 0);
  vector<int> upperDia((2 * n - 1), 0);

  solve_hash(ans, board, leftRow, lowerDia, upperDia);
  return ans;
}

int main() {
  int n;
  cin >> n;

  vector<vector<string>> ans;
  vector<string> board(n);
  string s(n, '.');
  for (int i = 0; i < n; i++)
    board[i] = s;

  // solve(ans, board);

  vector<vector<string>> ans_hash = solveNQueens_hash(n);


  int solution_num = 1;
  for (const auto& solution : ans_hash) {
    cout << "\nSolution " << solution_num++ << ":\n";
    printChessBoard(solution);
    cout << endl;
  }

  return 0;
}

/*
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
*/