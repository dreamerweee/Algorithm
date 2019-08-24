/*
* 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度
*/

int LongestValidParentheses(string s)
{
	typedef string::size_type s_type;
	s_type len = s.size();
	int max = 0;
	if (len < 2)
		return max;

	stack<s_type> idx_stk;
	idx_stk.push(-1);  // 先将-1压入栈，计算有效长度时避免特殊处理
	for (s_type i = 0; i < len; ++i) {
		if (s[i] == '(') {
			idx_stk.push(i);
		} else {
			idx_stk.pop();   // 如果是')'，则栈顶元素出栈
			if (idx_stk.empty()) {
				idx_stk.push(i);
			} else {
				int cur = i - idx_stk.top();
				if (max < cur)
					max = cur;
			}
		}
	}

	return max;
}