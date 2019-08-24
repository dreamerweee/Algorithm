/*
* 根据逆波兰表示法，求表达式的值。
* 有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
* 说明：
*	整数除法只保留整数部分。
*	给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
*/

int EvalRPN(vector<string> &tokens)
{
	stack<int> ret_stk;
	for (auto s : tokens) {
		if (s == "+" || s == "-" || s == "*" || s == "/") {
			int calc1 = ret_stk.top();
			ret_stk.pop();
			int calc2 = ret_stk.top();
			ret_stk.pop();
			int res = 0;
			if (s == "+")
				res = calc1 + calc2;
			else if (s == "-")
				res = calc2 - calc1;
			else if (s == "*")
				res = calc1 * calc2;
			else
				res = calc2 / calc1;
			ret_stk.push(res);
		} else {
			ret_stk.push(stoi(s));
		}
	}
	return ret_stk.top();
}