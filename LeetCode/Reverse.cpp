/*
* 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
*/

int Reverse(int x)
{
	long x1 = x;
	bool neg = false;
	if (x1 < 0) {
		neg = true;
		x1 = -x1;
	}
	long result = 0;
	while (x1 > 0) {
		result = result * 10 + x1 % 10;
		x1 = x1 / 10;
	}
	if (neg) {
		if (-result < INT_MIN)
			result = 0;
	} else {
		if (result > INT_MAX)
			result = 0;
	}

	return neg ? -result : result;
}