// OJ: https://leetcode.com/problems/surrounded-regions/
// Author: github.com/elaijuh
// Time: O(n*m)
// Space: O()
class Solution {
 public:
  void solve(vector<vector<char>>& board) {
    int n = board.size();
    if (n == 0) return;
    int m = board[0].size();
    for (int i = 0; i < m; ++i) {
      if (board[0][i] == 'O') dfs(board, 0, i, n, m);          //
      if (board[n - 1][i] == 'O') dfs(board, n - 1, i, n, m);  //
    }
    for (int i = 0; i < n; ++i) {
      if (board[i][0] == 'O') dfs(board, i, 0, n, m);          //
      if (board[i][m - 1] == 'O') dfs(board, i, m - 1, n, m);  //
    }
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        if (board[i][j] == 'O') board[i][j] = 'X';
        if (board[i][j] == 'P') board[i][j] = 'O';
      }
  }
  void dfs(vector<vector<char>>& board, int i, int j, int n, int m) {
    if (i >= 0 && i < n && j >= 0 && j < m && board[i][j] == 'O') {
      board[i][j] = 'P';
      dfs(board, i - 1, j, n, m);
      dfs(board, i, j + 1, n, m);
      dfs(board, i + 1, j, n, m);
      dfs(board, i, j - 1, n, m);
    }
    return;
  }
};
