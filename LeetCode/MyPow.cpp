/* 
* 实现 pow(x, n) ，即计算 x 的 n 次幂函数。
*/

// 递归实现
double Pow(double x, int n)
{
    if (n == 0) {
        return 1.0;
    }
    double half = Pow(x, n / 2);
    if (n % 2 == 0) {
        return half * half;
    } else {
        return x *half * half;
    }
}

double myPow(double x, int n) {
    long long big_n = n;
    if (big_n < 0) {
        big_n = -big_n;
        x = 1 / x;
    }
    return Pow(x, big_n);
}

// 循环实现
double MyPow(double x, int n)
{
    long long big_n = n;
    if (big_n < 0) {
        x = 1 / x;
        big_n = -big_n;
    }
    double result = 1.0;
    double current = x;
    for (long long i = big_n; i >= 1; i /= 2) {
        if (i % 2 == 1) {
            result *= current;
        }
        current *= current;
    }
    return result;
}
