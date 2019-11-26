/*
* 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
* 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
*/

int MaxProfit2(vector<int>& prices)
{
	size_t len = prices.size();
	if (len <= 1) {
		return 0;
	}

	int max_profit = 0;
	for (int i = 1; i < len; ++i) {
		if (prices[i] > prices[i - 1]) {
			max_profit += prices[i] - prices[i - 1];
		}
	}
	return max_profit;
}