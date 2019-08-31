/*
* 给定一个字符串，逐个翻转字符串中的每个单词
*/

string ReverseWords(string s)
{
	vector<string> vec;
	string res;
	istringstream str_in(s);
	while (str_in >> res) {
		vec.push_back(res);
	}

	res = "";
	auto rbeg = vec.rbegin();
	while (rbeg != vec.rend()) {
		if (res != "")
			res += " ";
		res += *rbeg;
		++rbeg;
	}

	return res;
}

string ReverseWords(string s)
{
	string ret_str("");
	string::size_type len = s.size();
	int end_idx = -1;
	for (int i = len - 1; i >= 0; --i) {
		if (end_idx == -1 && !isspace(s[i])) {
			end_idx = i;
		} else if (end_idx != -1 && isspace(s[i])) {
			if (ret_str != "")
				ret_str += " ";
			for (int j = i + 1; j <= end_idx; ++j)
				ret_str += s[j];
			end_idx = -1;
		}
	}

	if (end_idx != -1) {
		if (ret_str != "")
			ret_str += " ";
		for (int j = 0; j <= end_idx; ++j)
			ret_str += s[j];
	}
	return ret_str;
}