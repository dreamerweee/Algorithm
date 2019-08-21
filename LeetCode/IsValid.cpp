/*
* 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
* 有效字符串需满足：
*	左括号必须用相同类型的右括号闭合。
*	左括号必须以正确的顺序闭合。
* 注意空字符串可被认为是有效字符串。
*/

bool IsValid(string s)
{
	if (s.size() % 2 == 1)  // 奇数长度肯定无效
		return false;

	stack<char> c_stk;
	for (auto e : s) {
		if (e == '(' || e == '{' || e == '[') {
			c_stk.push(e);
		} else {
			if (c_stk.empty()) {
				return false;
			} else {
				char c = c_stk.top();
				if ((e == ')' && c != '(') || (e == ']' && c != '[') || (e == '}' && c != '{'))
					return false;
				c_stk.pop();
			}
		}
	}
	if (c_stk.empty())
		return true;
	else
		return false;
}