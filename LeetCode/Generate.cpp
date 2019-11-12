/*
* 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行
*/
vector<vector<int>> Generate(int numRows)
{
	vector<vector<int>> result(numRows);
	for (int i = 0; i < numRows; ++i) {
		result[i].push_back(1);
		int j = 1;
		for (; j < i; ++j) {
			result[i].push_back(result[i-1][j-1] + result[i-1][j]);
		}
		if (j == i) {
			result[i].push_back(1);
		}
	}
	return result;
}
