/*
* 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
* 说明:
* 	初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
* 	你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
*/

void Merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	long int max = m + n - 1;
	int max1 = m - 1, max2 = n - 1;
	while (max1 >= 0 || max2 >= 0) {
		if (max1 >= 0 && max2 >= 0) {
			if (nums1[max1] > nums2[max2]) {
				nums1[max] = nums1[max1];
				--max1;
			} else {
				nums1[max] = nums2[max2];
				--max2;
			}
		} else if (max1 >= 0) {
			nums1[max] = nums1[max1];
			--max1;
		} else {
			nums1[max] = nums2[max2];
			--max2;
		}
		--max;
	}
} 