/*
* 实现 strStr() 函数。
* 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。
* 如果不存在，则返回  -1。
*/
// 暴力求解，时间复杂度太高，应该使用KMP算法
int StrStr(string haystack, string needle)
{
  if (needle.empty()) {
    return 0;
  }
  if (haystack.empty()) {
    return -1;
  }

  int h_idx = 0;
  int n_idx = 0;
  int h_len = haystack.size();
  int n_len = needle.size();
  for (; h_idx < h_len; ++h_idx) {
    if (haystack[h_idx] == needle[n_idx]) {
      for (; n_idx < n_len; ++n_idx) {
        if (haystack[h_idx+n_idx] != needle[n_idx]) {
          n_idx = 0;
          break;
        }
      }
      if (n_idx == n_len) {
        return h_idx;
      }
    }
  }
  if (h_idx == h_len) {
    h_idx = -1;
  }

  return h_idx;
}