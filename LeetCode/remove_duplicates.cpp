/*
* 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，
* 返回移除后数组的新长度。
* 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

* 不需要考虑数组中超出新长度后面的元素
*/

/*
* 思想：令新的长度为0，从数组下标1开始检查，如果当前下标对应的数组值与新数组的当前下标对应值
* 相等，则肯定不用更新新数组的内容，只有不等的时候才进行更新
* 可以这样想：现在要做的就是从一个有序数组中拿出不一样的值到新数组中去
*/
int RemoveDuplicates(vector<int> &nums)
{
  auto len = nums.size();
  if (len <= 1) {
    return len;
  }
  size_t new_len = 0;
  for (int i = 1; i < len; ++i) {
    if (nums[i] != nums[new_len]) {
      nums[++new_len] = nums[i];
    }
  }
  return new_len + 1;
}


