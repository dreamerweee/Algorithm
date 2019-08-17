/*
* 给定一个未排序的整数数组，找出其中没有出现的最小的正整数。
* 要求时间复杂度为O(n)，空间复杂度为O(1)
*/

static void Swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

/*
* 假设数组的长度为n，则缺失的正整数肯定在1～n+1之中
* 遍历数组，将当前数值(大于0小于等于n)放到正确的位置：m放在nums[m-1]
*/
int FirstMissingPositive(vector<int> &nums)
{
	typedef vector<int>::size_type size_tp;
	size_tp len = nums.size();
	for (size_tp i = 0; i < len; ++i) {
		// 如果有相同元素会造成死循环
		// 为防止死循环，nums[i] == nums[nums[i]-1]时，不交换
		while (nums[i] > 0 && nums[i] <= len && nums[i] != i + 1 && nums[i] != nums[nums[i]-1]) {
			Swap(nums[i], nums[nums[i]-1]);
		}
	}

	int miss_val = len + 1;
	for (size_tp i = 0; i < len; ++i) {
		if (nums[i] != i + 1) {
			miss_val = i + 1;
			break;
		}
	}
	return miss_val;
}