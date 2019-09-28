/*
* 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
* 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
* 你可以假设除了整数 0 之外，这个整数不会以零开头。
*/

vector<int> PlusOne(vector<int>& digits)
{
	size_t len = digits.size();
	vector<int>  result(len);
	int plus = 1;
	for (long i = len - 1; i >= 0; --i) {
		int res = digits[i] + plus;
		result[i] = res % 10;
		plus = res / 10;
	}
	if (plus) {
		result.insert(result.begin(), plus);
	}
	return result;
}