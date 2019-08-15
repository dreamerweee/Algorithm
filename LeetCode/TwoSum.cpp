/*
* 给定一个整数数组 arr 和一个目标值 target ，请在该数组中找出和为目标值的那两个整数，并返回它们的数组下标。
* 假设每种输入只会对应一个答案，但是，不能重复利用这个数组中同样的元素。
*/

// 暴力求解
vector<int> TwoSum(vector<int> &arr, int target)
{
	typedef vector<int>::size_type size_type;
	size_type len = arr.size();

	if (len <= 1)
		return {};

	for (size_type i = 0; i < len - 1; ++i) {
		for (size_type j = i + 1; j < len; ++j) {
			if (arr[i] + arr[j] == target) {
				return {i, j};
			}
		}
	}

	return {};  // 未找到
}

// 利用unordered_map，时间复杂度为O(n)
vector<int> TwoSum2(vector<int> &arr, int target)
{
	typedef vector<int>::size_type size_type;
	size_type len = arr.size();
	if (len <= 1)
		return {};

	unordered_map<int, size_type> value_map;
	for (size_type i = 0; i < len; ++i) {
		value_map[arr[i]] = i;
	}

	for (size_type i = 0; i < len; ++i) {
		int left = target - arr[i];
		auto res = value_map.find(left);
		if (res != value_map.end()) {
			return {i, res->second};
		}
	}

	return {};  // 未找到
}
