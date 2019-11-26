/*
* 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
*/

string LongestPalindrome(string s)
{
	size_t len = s.size();
	if (len <= 1) {
		return s;
	}

	for (size_t left = 0; letf < len; ++left) {
		for (size_t right = len - 1; right > 0; --right) {
			if (s[left] == s[right]) {
				
			}
		}
	}
}