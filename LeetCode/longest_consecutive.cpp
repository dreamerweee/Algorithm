/*
* 给定一个未排序的整数数组，找出最长连续序列的长度。
* 要求算法的时间复杂度为 O(n)。
*/

/*
* 肯定不能使用排序了
* 首先想到使用哈希表
* 将数组中的数存入哈希表中，再遍历数组，使用当前元素来检查连续的数据
*/
int LongestConsecutive(vector<int> &nums)
{
    unordered_set<int> nums_set;
    for (auto i : nums) {
        nums_set.insert(i);
    }

    int longest = 0;
    for (auto i : nums) {
        int len = 1;
        // 往前查找
        for (int j = i - 1; nums_set.find(j) != nums_set.end(); --j) {
            ++len;
            nums_set.erase(j);
        }
        // 向后查找
        for (int j = i + 1; nums_set.find(j) != nums_set.end(); ++j) {
            ++len;
            nums_set.erase(j);
        }

        longest = max(longest, len);
    }

    return longest;
}