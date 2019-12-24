/*
* 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
* 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
* 问总共有多少条不同的路径？
*/

/*
* 动态规划
*   1、找到状态数组的含义
*   2、找到状态转移方程
*   3、找到初始值
*/
int UniquePaths(int m, int n)
{
  vector<vector<int>> states(m, vector<int>(n));
  // 初始化第0行
  for (int j = 0; j < n; ++j) {
    states[0][j] = 1;  // 只有一条路径，一直在最上面走
  }

  // 初始化第0列
  for (int i = 0; i < m; ++i) {
    states[i][0] = 1;  // 也只有一条路径，一直往下走
  }

  // 填表
  for (int i = 1; i < m; ++i) {
    for (int j = 1; j < n; ++j) {
      states[i][j] = states[i-1][j] + states[i][j-1];
    }
  }

  return states[m-1][n-1];
}