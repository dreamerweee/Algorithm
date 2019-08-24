/*
** 给定一个包含n个整数的数组nums
** 判断nums中是否存在三个元素a, b, c, 使得 a + b + c = 0 
** 找出所有满足条件且不重复的三元组
*/

/*
** 思路：因为数组是乱序的，如果不排序直接暴力求解，则时间复杂度为O(n^3)
** 排序之后，将问题转化为两数之和求解，时间复杂度为O(n^2)
*/

vector<vector<int>> ThreeSum(vector<int> &arr, int key)
{
	if (arr.size() < 3) {
		return {};  // 不可能找到
	}
	
	// 先排序
	sort(arr.begin(), arr.end());

	typedef vector<int>::size_type size_tp;

	size_tp sz = arr.size();
	vector<vector<int>> result;  // 存储结果
	
	for (size_tp i = 0; i < sz - 2; ++i) {
		int left_val = key - arr[i]; // 剩下两数之和为left_val
		size_tp j = i + 1;
		size_tp k = sz - 1;
		while (j < k) {
			if (arr[j] + arr[k] > left_val) {
				--k;
			} else if (arr[j] + arr[k] < left_val) {
				++j;
			} else {
				result.push_back({arr[i], arr[j], arr[k]});
				while (j < k && arr[j] == arr[j+1]) ++j;
				while (j < k && arr[k] == arr[k-1]) --k;
				++j;
				--k;
			}
		}
		while (i < sz - 1 && arr[i] == arr[i+1])
			i++;
	}

	return result;
}
