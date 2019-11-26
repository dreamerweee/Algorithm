/*
* 给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
*/

bool IsPowerOfTwo(int n)
{
	if (n <= 0) {
		return false;
	}
	if (n == 1) {
		return true;
	}
	long calc = 1;
	for (int i = 1; i < n; ++i) {
		calc *= 2;
		if (n == calc) {
			return true;
		} else if (calc > n) {
			return false;
		}
	}
	return false;
}

// leetcode解法
bool IsPowerOfTwo(int n)
{
	return (n > 0) && ((n & (n-1)) == 0);
}