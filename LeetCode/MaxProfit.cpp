/*
* 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
* 如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
* 注意你不能在买入股票前卖出股票。
*/

int MaxProfit(vector<int>& prices)
{
	typedef vector<int>::size_type s_type;
	s_type len = prices.size();
	if (len <= 1) {
		return 0;
	}
	int min = INT_MAX;
	int max_value = 0;
	for (s_type i = 0; i < len; ++i) {
		if (prices[i] < min) {
			min = prices[i];
		} else if (prices[i] - min > max_value) {
			max_value = prices[i] - min;
		}
	}

	return max_value;
}