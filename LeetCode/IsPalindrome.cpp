/*
* 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
*/

bool IsPalindrome(int x)
{
	if (x < 0) {
		return false;
	}
	if (x < 10) {
		return true;
	}

	int y = x, res = 0;
	while (y > 0) {
		res = res * 10 + y % 10;
		y /= 10;
	}

	return x == res;
}