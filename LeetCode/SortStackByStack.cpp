/*
* 一个栈中元素的类型为整型，现在想将该栈从顶到底按从大到小的顺序排序，只许申请一个栈。
* 如何完成排序？
*/

#include <iostream>
#include <stack>

using namespace std;

void SortStackByStack(stack<int> &_stack)
{
	stack<int> help_stack;
	while (!_stack.empty()) {
		int stk_val = _stack.top();
		_stack.pop();
		while (!help_stack.empty() && help_stack.top() < stk_val) {
			int help_val = help_stack.top();
			help_stack.pop();
			_stack.push(help_val);
		}
		help_stack.push(stk_val);
	}
	while (!help_stack.empty()) {
		_stack.push(help_stack.top());
		help_stack.pop();
	}
}

int main()
{
	stack<int> stack({7,3,5,9,2,1,4,0,8,6});
	cout << "top value = " << stack.top() << endl;

	SortStackByStack(stack);
	while (!stack.empty()) {
		cout << "value = " << stack.top() << endl;
		stack.pop();
	}

	return 0;
}