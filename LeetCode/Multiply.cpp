/*
* 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
*/

string Multiply(string num1, string num2)
{
	map<const char, int> trans = {
		{'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4},
		{'5', 5}, {'6', 6}, {'7', 7}, {'8', 8},{'9', 9}
	};
	int len1 = num1.size();
	int len2 = num2.size();
	string result(len1 + len2, '0');

	int cur1, cur2;
	int carry;
	int res;
	for (int i = 0, idx1 = len1 - 1; idx1 >= 0; --idx1, ++i) {
		cur1 = trans[num1[idx1]];
		carry = 0;
		int j = 0;
		for (int idx2 = len2 - 1; idx2 >= 0; --idx2, ++j) {
			cur2 = trans[num2[idx2]];
			res = trans[result[i + j]];
			res += cur1 * cur2 + carry;
			carry = res / 10;
			res = res % 10;
			result[i + j] = '0' + res;
		}
		if (carry > 0) {
			result[i + j] = '0' + carry;
		}
	}
	string ret;
	for (int i = result.size() - 1; i >= 0; --i) {
		if (result[i] != '0' || ret != "") {
			ret += result[i];
		}
	}
	if (ret == "") {
		ret = "0";
	}
	return ret;
}