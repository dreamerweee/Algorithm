/*
* 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，
* 返回移除后数组的新长度。
* 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
* 不需要考虑数组中超出新长度后面的元素
*/

/*
* 思想：从有序数组中拿数据，相同的数据最多拿两次
*/
int RemoveDuplicates(vector<int> &nums)
{
  auto len = nums.size();
  if (len <= 2) {
    return len;
  }

  size_t new_len = 0;
  int curr_count = 1;
  for (size_t i = 1; i < len; ++i) {
    if (nums[new_len] == nums[i] && curr_count == 1) {
      nums[++new_len] = nums[i];
      ++curr_count;
    } else if (nums[new_len] != nums[i]) {
      nums[++new_len] = nums[i];
      curr_count = 1;
    }
  }
  return new_len + 1;
}

// 上面代码还可以简化
{
  // ...

  size_t new_len = 2;
  for (size_t i = 2; i < len; ++i) {
    if (nums[i] != nums[new_len - 2]) {
      nums[new_len++] = nums[i];
    }
  }

  return new_len;
}