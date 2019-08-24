/*
* 给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
* 只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
* 返回滑动窗口中的最大值。
*/

// 暴力求解
vector<int> MaxSlidingWindow(vector<int> &nums, int k)
{
	if (nums.size() == 0)
		return {};
	typedef vector<int>::size_type s_type;
	s_type left = 0;
	s_type right = k - 1;
	s_type len = nums.size() - 1;
	vector<int> result;
	while (right <= len) {
		int max_val = nums[right];
		for (int i = left; i < right; ++i) {
			if (nums[i] > max_val)
				max_val = nums[i];
		}
		++left;
		++right;
		result.push_back(max_val);
	}
	return result;
}

// 采用双端队列的方法，deque保存数组的下标，滑动窗口内最大值的下标在队列头，最小的在队列尾
vector<int> MaxSlidingWindow2(vector<int> &nums, int k)
{
	typedef vector<int>::size_type s_type;
	s_type len = nums.size();
	if (len == 0 || len < k)
		return {};

	deque<s_type> idx_que;
	vector<int> result;

	// 使用数组前k个元素初始化队列
	for (int i = 0; i < k; ++i) {
		while (!idx_que.empty() && nums[i] >= nums[idx_que.back()]) {
			idx_que.pop_back();
		}
		idx_que.push_back(i);
	}
	result.push_back(nums[idx_que.front()]);

	// 处理后面的元素
	for (int i = k; i < len; ++i) {
		while (!idx_que.empty() && idx_que.front() <= i - k) {
			idx_que.pop_front();
		}
		while (!idx_que.empty() && nums[i] >= nums[idx_que.back()]) {
			idx_que.pop_back();
		}
		idx_que.push_back(i);
		result.push_back(nums[idx_que.front()]);
	}

	return result;
}