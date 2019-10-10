/*
* 给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
* 如果不存在最后一个单词，请返回 0 。
* 说明：一个单词是指由字母组成，但不包含任何空格的字符串。
*/

int LengthOfLastWord(string s)
{
	if (s.size() == 0) {
		return 0;
	}
	string::size_type sz = s.size();
	int len = 0;
	for (int i = sz - 1; i >= 0; --i) {
		if (isspace(s[i])) {  // 忽略末尾空格
			if (len != 0)
				return len;
		} else {
			++len;
		}
	}
	return len;
}