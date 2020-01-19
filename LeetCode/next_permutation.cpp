/*
* 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中
* 下一个更大的排列。
* 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
* 必须原地修改，只允许使用额外常数空间。
* 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
    1,2,3 → 1,3,2
    3,2,1 → 1,2,3
    1,1,5 → 1,5,1
*/

/*
* 我的理解就是把当前数组连起来看作一个大整数，要求找出下一个比此大的数
* 分析：从右往左遍历，找到第一个破坏升序规则的数
*       再从右往左遍历，找到第一个比A大的数B，交换
*       最后，逆序B后面的数组
*/
void NextPermutation(vector<int> &nums)
{
    size_t len = nums.size();
    int curr_val = nums[len-1];
    long min_pos=len, max_pos;
    for (long idx = len - 2; idx >= 0; --idx) {
        if (nums[idx] < curr_val) {
            min_pos = idx;
            curr_val = nums[idx];
            break;
        } else {
            curr_val = nums[idx];
        }
    }
    if (min_pos != len) {
        for (long idx = len - 1; idx >= 0; --idx) {
            if (nums[idx] > curr_val) {
                max_pos = idx;
                break;
            }
        }
        swap(nums[min_pos], nums[max_pos]);
    } else {
        min_pos = -1;
    }
    // 逆序min_pos后面的数组
    ++min_pos;
    max_pos = len - 1;
    while (min_pos < max_pos) {
        int temp = nums[min_pos];
        nums[min_pos] = nums[max_pos];
        nums[max_pos] = temp;
        ++min_pos;
        --max_pos;
    }
}