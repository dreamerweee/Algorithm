/*
* 给定一个整数数组，判断是否存在重复元素。
* 如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。
*/

// 利用hash表O(n)时间复杂度解决
bool ContainsDuplicate(vector<int>& nums)
{
	unordered_map<int, bool> hash_map;
	for (auto e : nums) {
		auto itr = hash_map.find(e);
		if (itr != hash_map.end()) {
			return true;
		}
		hash_map[e] = true;
	}
	return false;
}