/*
* 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，
* 同时保持非零元素的相对顺序。
*/
void MoveZeroes(vector<int> &nums)
{
    size_t idx = 0;
    size_t len = nums.size();
    for (size_t i = 0; i < len; ++i) {
        if (nums[i] != 0) {
            nums[idx++] = nums[i];
        }
    }
    while (idx < len) {
        nums[idx++] = 0;
    }
}