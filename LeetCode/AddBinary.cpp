/*
* 给定两个二进制字符串，返回他们的和（用二进制表示）。
* 输入为非空字符串且只包含数字 1 和 0。
*/

string AddBinary(string a, string b)
{
	string res("");
	int idx_a = a.size() - 1;
	int idx_b = b.size() - 1;
	char carry = '0';
	char cur;
	while (idx_a >= 0 || idx_b >= 0) {
		cur = carry;
		if (idx_a >= 0) {
			cur += a[idx_a] - '0';
		}
		if (idx_b >= 0) {
			cur += b[idx_b] - '0';
		}
		if (cur >= '2') {
			res.push_back(cur - 2);
			carry = '1';
		} else {
			res.push_back(cur);
			carry = '0';
		}
		--idx_a;
		--idx_b;
	}
	if (carry == '1')
		res += "1";

	string::size_type idx_beg = 0;
	string::size_type idx_end = res.size() - 1;
	while (idx_beg < idx_end) {
		swap(res[idx_beg], res[idx_end]);
		idx_beg++;
		idx_end--;
	}

	return res;
}