/*
* 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
* 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
* 注意：给定 n 是一个正整数。
*/

// 递归，timeout
int ClimbStairs(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	return ClimbStairs(n - 1) + ClimbStairs(n - 2);
}

int ClimbStairs(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	int ppre = 1;
	int pre = 2;
	int cur;
	for (int i = 3; i <= n; ++i) {
		cur = ppre + pre;
		ppre = pre;
		pre = cur;
	}
	return cur;
}