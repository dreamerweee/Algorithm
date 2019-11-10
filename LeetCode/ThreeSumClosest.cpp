/*
* 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。
* 找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。
* 假定每组输入只存在唯一答案。
*/

inline int GetClosest(int target, int a, int b)
{
	int sub_a = target - a;
	if (sub_a < 0) {
		sub_a = -sub_a;
	}
	int sub_b = target - b;
	if (sub_b < 0) {
		sub_b = -sub_b;
	}
	return sub_a < sub_b ? a : b;
}

int ThreeSumClosest(vector<int>& nums, int target)
{
	// 先排序
	sort(nums.begin(), nums.end());
	int result = nums[0] + nums[1] + nums[2];
	size_t sz = nums.size();

	for (size_t i = 0; i < sz - 2; ++i) {
		size_t j = i + 1;
		size_t k = sz - 1;
		while (j < k) {
			int sum = nums[i] + nums[j] + nums[k];
			result = GetClosest(target, result, sum);
			if (sum > target) {
				--k;
			} else if (sum < target) {
				++j;
			} else {
				return result;
			}
		}
	}

	return result;
}