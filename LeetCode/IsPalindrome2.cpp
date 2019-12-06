/*
* 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
* 说明：本题中，我们将空字符串定义为有效的回文串。
*/
bool IsPalindrome(string s)
{
	bool result = true;
	int left = 0, right = s.size() - 1;
	while (left < right) {
		if (!isalnum(s[left])) {
			++left;
			continue;
		}
		if (!isalnum(s[right])) {
			--right;
			continue;
		}
		if (tolower(s[left]) != tolower(s[right])) {
			result = false;
			break;
		}
		++left;
		--right;
	}
	return result;
}