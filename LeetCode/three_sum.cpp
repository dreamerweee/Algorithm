/*
* 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
* 使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
* 答案中不可以包含重复的三元组。
*
*  给定数组 nums = [-1, 0, 1, 2, -1, -4]，
*  满足要求的三元组集合为：
*  [
*    [-1, 0, 1],
*    [-1, -1, 2]
*  ]
*/

/*
* 先对数组进行排序，然后左右夹逼，时间复杂度O(n^2)
*/
vector<vector<int>> ThreeSum(vector<int> &nums)
{
    vector<vector<int>> result;
    size_t len = nums.size();
    if (len < 3) {
        return {};
    }
    if (len == 3) {
        if (nums[0] + nums[1] + nums[2] == 0) {
            result.push_back(nums);
        }
        return result;
    }
    sort(nums.begin(), nums.end());
    for (size_t i = 0; i < len - 2; ++i) {
        if (i > 0 && nums[i] == nums[i-1])
            continue;
        if (nums[i] > 0) {
            break;  // 后面不可能再存在和为负的情况了
        }
        size_t j = i + 1, k = len - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                result.push_back({nums[i], nums[j], nums[k]});
                ++j;
                --k;
                while (nums[j] == nums[j-1] && j < k )
                    ++j;
                while (nums[k] == nums[k+1] && k > j)
                    --k;
            } else if (sum < 0) {
                ++j;
                while (nums[j] == nums[j-1] && j < k )
                    ++j;
            } else {
                --k;
                while (nums[k] == nums[k+1] && k > j)
                    --k;
            }
        }
    }
    return result;
}