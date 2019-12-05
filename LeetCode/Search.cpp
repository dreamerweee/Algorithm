/*
* 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
* ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
* 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
* 你可以假设数组中不存在重复的元素。
* 你的算法时间复杂度必须是 O(log n) 级别。
*/

int Search(vector<int> &vect, int value)
{
	if (vect.empty()) {
		return -1;
	}
	
	int len = vect.size();
	int left = 0, right = len - 1;
	while (left <= right) {
		int mid = left + ((right - left) >> 1);
		if (vect[mid] == value) {
			return mid;
		}
		if (vect[left] <= vect[mid]) {
			if (value <= vect[mid] && value >= vect[left]) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		} else {
			if (value >= vect[mid] && value <= vect[right]) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
	}
	return -1;
}