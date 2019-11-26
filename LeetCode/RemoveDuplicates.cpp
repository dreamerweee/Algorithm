/*
* 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
* 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
*/

int RemoveDuplicates(vector<int>& nums)
{
	size_t len = nums.size();
	if (len <= 1) {
		return len;
	}

	size_t new_len = 1;
	int last_val = nums[0];
	for (size_t i = 1; i < len; ++i) {
		if (nums[i] != last_val) {
			nums[new_len] = nums[i];
			last_val = nums[i];
			++new_len;
		}
	}
	return new_len;
}