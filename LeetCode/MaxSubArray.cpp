/*
* 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
*/

int MaxSubArray(vector<int>& nums)
{
	int max_sum = INT_MIN;
	size_t len = nums.size();
	if (len == 0) {
		return max_sum;
	}

	int cur_sum = 0;
	for (size_t i = 0; i < len; ++i) {
		cur_sum += nums[i];
		if (cur_sum > max_sum) {
			max_sum = cur_sum;
		}
		if (cur_sum < 0) {
			cur_sum = 0;
		}
	}
	return max_sum;
}