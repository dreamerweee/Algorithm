/*
* 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
*/

string LongestPalindrome(string s)
{
	bool dp[1000][1000];
	auto len = s.size();
	string result;
	for (int i = len - 1; i >= 0; --i) {
		for (int j = i; j < len; ++j) {
			if (s[i] == s[j] && (j - i < 2 || dp[i+1][j-1])) {
				dp[i][j] = true;
			} else {
				dp[i][j] = false;
			}
			if (dp[i][j] && j - i + 1 > result.size()) {
				result = s.substr(i, j-i+1);
			}
		}
	}
	return result;
}