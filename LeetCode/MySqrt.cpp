/*
* 实现 int sqrt(int x) 函数。
* 计算并返回 x 的平方根，其中 x 是非负整数。
* 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
*/

int MySqrt(int x)
{
	if (x == 0 || x == 1)
		return x;
	int guess = x / 2;
	while (true) {
		int s = guess;
		int ss = guess + 1;
		if ( (x / s >= s) && (x / ss < ss) )
			return s;
		guess = (guess + x / guess) / 2;
	}
	return 0;
}