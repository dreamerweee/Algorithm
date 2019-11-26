/*
* 编写一个函数来查找字符串数组中的最长公共前缀。
* 如果不存在公共前缀，返回空字符串 ""。
*/

string LongestCommonPrefix(vector<string>& strs)
{
	size_t len = strs.size();
	if (len == 0) {
		return "";
	}
	
	string ret_str = "";
	string first = strs[0];
	for (size_t i = 0; i < first.size(); ++i) {
		for (size_t j = 1; j < len; ++j) {
			if (strs[j][i] != first[i]) {
				return ret_str;
			}
		}
		ret_str += first[i];
	}
	return ret_str;
}