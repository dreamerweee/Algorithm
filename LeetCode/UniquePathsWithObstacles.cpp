/*
* 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
* 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
* 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
* 网格中的障碍物和空位置分别用 1 和 0 来表示。
*/

int UniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
  auto m = obstacleGrid.size();
  auto n = obstacleGrid[0].size();
  if (obstacleGrid[0][0] == 1) {
    return 0;
  }
  vector<vector<long>> path_nums(m, vector<long>(n));
  for (int j = 0; j < n; ++j) {
    if (obstacleGrid[0][j] == 1) {
      path_nums[0][j] = 0;
    } else if (j != 0) {
      path_nums[0][j]  = path_nums[0][j - 1];
    } else {
      path_nums[0][j] = 1;
    }
  }

  for (int i = 0; i < m; ++i) {
    if (obstacleGrid[i][0] == 1) {
      path_nums[i][0] = 0;
    } else if (i != 0) {
      path_nums[i][0] = path_nums[i-1][0];
    } else {
      path_nums[i][0] = 1;
    }
  }

  for (int i = 1; i < m; ++i) {
    for (int j = 1; j < n; ++j) {
      if (obstacleGrid[i][j] == 1) {
        path_nums[i][j] = 0;
      } else {
        path_nums[i][j] = path_nums[i-1][j] + path_nums[i][j-1];
      }
    }
  }

  return path_nums[m - 1][n - 1];
}