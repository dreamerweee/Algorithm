/* 
* 给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
* 你可以对一个单词进行如下三种操作：
*   插入一个字符
*   删除一个字符
*   替换一个字符
*/

int Min(int x, int y, int z)
{
  int min = INT_MAX;
  if (x < min) min = x;
  if (y < min) min = y;
  if (z < min) min = z;
  return min;
}

int MinDistance(string word1, string word2)
{
  int m = word1.size();
  int n = word2.size();
  if (m * n == 0) {
    return m + n;
  }
  vector<vector<int>> min_dist(m, vector<int>(n));
  for (int j = 0; j < n; ++j) {
    if (word1[0] == word2[j]) {
      min_dist[0][j] = j;
    } else if (j != 0) {
      min_dist[0][j] = min_dist[0][j-1] + 1;
    } else {
      min_dist[0][j] = 1;
    }
  }
  for (int i = 0; i < m; ++i) {
    if (word2[0] == word1[i]) {
      min_dist[i][0] = i;
    } else if (i != 0) {
      min_dist[i][0] = min_dist[i-1][0] + 1;
    } else {
      min_dist[i][0] = 1;
    }
  }

  for (int i = 1; i < m; ++i) {
    for (int j = 1; j < n; ++j) {
      if (word1[i] == word2[j]) {
        min_dist[i][j] = min_dist[i-1][j-1];
      } else {
        min_dist[i][j] = Min(min_dist[i-1][j-1], min_dist[i-1][j], min_dist[i][j-1]) + 1;
      }
    }
  }

  return min_dist[m-1][n-1];
}