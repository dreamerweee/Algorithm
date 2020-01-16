/*
* 最接近的三数之和
* 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。
* 找出 nums 中的三个整数，使得它们的和与 target 最接近。
* 返回这三个数的和。假定每组输入只存在唯一答案。
* 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
* 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
*/

/*
* 先排序，然后左右夹逼，时间复杂度O(n^2)
*/
int ThreeSumClosest(vector<int> &nums, int target)
{
    int result;
    size_t len = nums.size();
    sort(nums.begin(), nums.end());
    int diff_value = INT_MAX;
    for (size_t i = 0; i < len - 2; ++i) {
        auto j = i + 1;
        auto k = len -1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            int diff = abs(sum - target);
            if (diff < diff_value) {
                result = sum;
                diff_value = diff;
            }
            if (sum < target) {
                ++j;
            } else if (sum > target) {
                --k;
            } else {
                return result;
            }
        }
    }
    return result;
}