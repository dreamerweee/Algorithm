/*
* 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
* 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
* 你可以假设 nums1 和 nums2 不会同时为空。
*/

/*
* 解题思路： 假设两个数组的长度分别为len1和len2, 
	那么偶数情况下，也就是要找 mid = (len1 + len2) / 2; ([mid-1] + [mid]) / 2 的值
	奇数情况下，找 [mid] / 2 的值
*/

// 时间复杂度不满足要求
double FindMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	size_t len1 = nums1.size();
	size_t len2 = nums2.size();
	size_t len = len1 + len2;
	size_t mid = len / 2;
	size_t idx1 = 0, idx2 = 0;
	size_t curr = 0;
	int last_value = 0, curr_value;
	while (idx1 < len1 || idx2 < len2) {
		if (idx1 < len1 && idx2 < len2) {
			if (nums1[idx1] < nums2[idx2]) {
				if (curr == mid)
					curr_value = nums1[idx1];
				else
					last_value = nums1[idx1];
				++idx1;
			}
			else {
				if (curr == mid)
					curr_value = nums2[idx2];
				else
					last_value = nums2[idx2];
				++idx2;
			}
		} else if (idx1 < len1) {
			if (curr == mid)
				curr_value = nums1[idx1];
			else
				last_value = nums1[idx1];
			++idx1;
		} else if (idx2 < len2) {
			if (curr == mid)
				curr_value = nums2[idx2];
			else
				last_value = nums2[idx2];
			++idx2;
		}
		if (curr == mid) {
			if (len % 2 == 0)
				return (last_value + curr_value) / 2.0;
			else
				return curr_value;
		}
		++curr;
	}
	return 0;
}

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

// 参考解答：https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu-b/
double FindMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	size_t m = nums1.size();
	size_t n = nums2.size();

	if (m > n) {
		return FindMedianSortedArrays(nums2, nums1);
	}

	size_t min = 0, max = m;
	size_t half = (m + n + 1) / 2;  // 加1为处理奇数的情况
	while (min <= max) {
		size_t i = (min + max) / 2;
		size_t j= half - i;
		if (i < max && nums2[j-1] > nums1[i]) {
			min = i + 1;
		} else if (i > min && nums1[i-1] > nums2[j]) {
			max = i - 1;
		} else {
			int max_left = 0;
			if (i == 0)
				max_left = nums2[j-1];
			else if (j == 0)
				max_left = nums1[i-1];
			else
				max_left = MAX(nums1[i-1], nums2[j-1]);
			if ((m + n) % 2 == 1)
				return max_left;

			int min_right = 0;
			if (i == m)
				min_right = nums2[j];
			else if (j == n)
				min_right = nums1[i];
			else
				min_right = MIN(nums1[i], nums2[j]);
			return (max_left + min_right) / 2.0;
		}
	}
	return 0.0;
}