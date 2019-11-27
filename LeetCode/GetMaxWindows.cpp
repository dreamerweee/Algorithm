/*
* 生成窗口最大值数组
* 有一个整型数组arr和一个大小为w的窗口从数组的最左边滑到最右边，窗口每次向右滑一个位置
* 每个窗口下的最大值组成一个数组返回
*/

vector<int> GetMaxWindows(vector<int> arr, size_t w)
{
	size_t len = arr.size();
	if (len == 0 || w == 0 || len < w) {
		return {};
	}

	vector<int> result;
	deque<int> queue;
	for (int i = 0; i < len; ++i) {
		while (!queue.empty() && queue.front() <= i - w) {
			queue.pop_front();
		}
		while (!queue.empty() && arr[i] >= arr[queue.back()]) {
			queue.pop_back();
		}
		queue.push_back(i);
		if (i >= w - 1) {
			result.push_back(arr[queue.front()]);
		}
	}
	return result;
}