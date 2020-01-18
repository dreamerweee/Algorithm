/*
* 给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，
* 返回移除后数组的新长度。
* 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外
* 空间的条件下完成。
* 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
*/

/*
* 直接把元素换到新长度的后一个位置
* 思路2：遍历数组，把不等于val的值拿到“新”数组中
*/
int RemoveElement(vector<int> &nums, int val)
{
    size_t len = nums.size();
    if (len == 0) {
        return 0;
    }
    size_t new_len = len;
    size_t idx = 0;
    while (idx < new_len) {
        if (nums[idx] == val) {
            nums[idx] = nums[--new_len];
        } else {
            ++idx;
        }
    }
    return new_len;
}