/*
* 给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，
	其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
* 输入: [1,2,3,4]
* 输出: [24,12,8,6]
* 请不要使用除法，且在 O(n) 时间复杂度内完成此题
*/

vector<int> ProductExceptSelf(vector<int>& nums)
{
	vector<int> result;
	int res = 1;
	for (size_t i = 0; i < nums.size(); ++i) {
		result.push_back(res);
		res *= nums[i];
	}
	res = 1;
	for (int i = nums.size() - 1; i >= 0; --i) {
		result[i] *= res;
		res *= nums[i];
	}
	return result;
}