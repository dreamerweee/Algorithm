/*
  给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。
  按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
    1 "123"
    2 "132"
    3 "213"
    4 "231"
    5 "312"
    6 "321"
  给定 n 和 k，返回第 k 个排列。
  说明：
    给定 n 的范围是 [1, 9]。
    给定 k 的范围是[1,  n!]。

*/

/*
* 思路：从最高位依次向低位确认应该放哪个数
* 例如：n = 4, k = 9
* 那么最高位固定时（比如为1），一共有 3 * 2 * 1个数
* 要求解第9个，则可以计算出最高位的数字: 9 / 6 + 1
* 按照此思路计算即可
*/

int Factorial(int n)
{
  if (n <= 1) {
    return 1;
  }
  return n * Factorial(n - 1);
}

string GetPermutation(int n, int k)
{
  string result;
  string s(n,'0');
  for (int i = 0; i < n; ++i) {
    s[i] += i + 1;
  }

  int fact = Factorial(n - 1);
  --k;  // 从0开始
  for (int i = n - 1; i > 0; k %= fact, fact /= i, --i) {
    auto itr  = next(s.begin(), k / fact);
    result.push_back(*itr);
    s.erase(itr);
  }
  result.push_back(s[0]);
  return result;
}