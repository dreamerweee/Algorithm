/*
** 给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
*/

int MajorityElement(vector<int> &nums)
{
	unordered_map<int, int> value_map;
	for (auto e : nums) {
		++value_map[e];
	}

	int cur_times = 0;
	int ret_val = 0;
	for (auto beg = value_map.cbegin(); beg != value_map.cend(); ++beg) {
		if (beg->second > cur_times) {
			cur_times  = beg->second;
			ret_val = beg->first;
		}
	}
	return ret_val;
}

/*
** Boyer-Moore算法
** 如果把众数记为+1，把其他数记为-1，将它们全部加起来，显然和大于0，从结果本身可以看出众数比其他数多
*/

int MajorityElement(vector<int> &nums)
{
	int cnt = 0;
	int maj_val;
	for (int e : nums) {
		if (cnt == 0) {
			maj_val = e;
			++cnt;
		} else if (e == maj_val) {
			++cnt;
		} else {
			--cnt;
		}
	}
	return maj_val;
}