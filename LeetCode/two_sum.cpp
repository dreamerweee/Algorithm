/*
* 给定一个整数数组 nums 和一个目标值 target，
* 请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
* 你可以假设每种输入只会对应一个答案。
* 但是，你不能重复利用这个数组中同样的元素。
*/

/*
* 暴力求解 时间复杂度为O(n^2)，会超时
*
* 排序法 先用哈希表记录下数组元素对应的下标，再给数组排序，
* 然后左右夹击，找到符合条件的值，最后返回值对应的下标
*   时间复杂度O(nlogn)、空间复杂度O(n)
*
* 利用哈希表存储数组元素及对应的下标，然后遍历数组，用目标值减去当前数组值，
* 根据得到的差值去哈希表中查找，如果存在则说明找到，时间复杂度O(n)
*/
vector<int> TwoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> num_idx_map;
    size_t len = nums.size();
    for (size_t i = 0; i < len; ++i) {
        num_idx_map[nums[i]] = i;
    }

    vector<int> result;
    for (size_t i = 0; i < len; ++i) {
        auto iter = num_idx_map.find(target - nums[i]);
        if (iter != num_idx_map.end()) {
            result.push_back(i);
            result.push_back(iter->second);
            break;
        }
    }

    return result;
}