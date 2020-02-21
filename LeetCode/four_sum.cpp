/*
* 四数之和
* 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，
* 使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
*/

vector<vector<int>> FourSum(vector<int>& nums, int target)
{
  vector<vector<int>> result;
  size_t len = nums.size();
  if (len < 4) {
    return result;
  }

  // 先排序
  sort(nums.begin(), nums.end());
  // 利用hashmap存两数之和
  unordered_map<int, vector<pair<int, int>>> two_sum_map;
  for (size_t i = 0; i < len - 1; ++i) {
    for (size_t j = i + 1; j < len; ++j) {
      int sum = nums[i]+nums[j];
      two_sum_map[sum].push_back(pair<int, int>(i, j));
    }
  }

  for (size_t i = 0; i < len - 1; ++i) {
    for (size_t j = i + 1; j < len; ++j) {
      const int key = target - nums[i] - nums[j];
      if (two_sum_map.find(key) == two_sum_map.end()) {
        continue;
      }
      const auto &vec = two_sum_map[key];
      for (size_t k = 0; k < vec.size(); ++k) {
        if (i <= vec[k].second) {
          continue;
        }
        result.push_back({nums[vec[k].first], nums[vec[k].second], nums[i], nums[j]});
      }
    }
  }

  sort(result.begin(), result.end());
  result.erase(unique(result.begin(), result.end()), result.end());

  return result;
}