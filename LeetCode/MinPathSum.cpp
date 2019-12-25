/*
* 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
* 说明：每次只能向下或者向右移动一步。
*/

int MinPathSum(vector<vector<int>>& grid)
{
  auto m = grid.size();
  if (m == 0) {
    return 0;
  }
  auto n = grid[0].size();

  vector<vector<int>> states(m, vector<int>(n));
  states[0][0] = grid[0][0];
  for (int j = 1; j < n; ++j) {
    states[0][j] = states[0][j-1] + grid[0][j];
  }
  for (int i = 1; i < m; ++i) {
    states[i][0] = states[i-1][0] + grid[i][0];
  }

  for (int i = 1; i < m; ++i) {
    for (int j = 1; j < n; ++j) {
      states[i][j] = min(states[i-1][j], states[i][j-1]) + grid[i][j];
    }
  }

  return states[m-1][n-1];
}