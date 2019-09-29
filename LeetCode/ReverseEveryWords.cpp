/*
* 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
*/

string ReverseEveryWords(string s)
{
	size_t len = s.size();
	if (len <= 1) {
		return s;
	}

	string res("");
	int beg = -1;
	for (size_t i = 0; i < len; ++i) {
		if (s[i] == ' ') {
			if (beg != -1) {
				for (int j = i - 1; j >= beg; --j) {
					res += s[j];
				}
				beg  = -1;
			}
			res += s[i];
		} else if (i == len - 1) {
			int end = i;
			if (beg != -1) {
				end = beg;
			}
			for (int j = i; j >= end; --j) {
				res += s[j];
			}
		}
		else if (beg == -1) {
			beg = i;
		}
	}

	return res;
}