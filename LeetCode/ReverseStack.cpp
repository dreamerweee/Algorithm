/*
* 使用递归和栈操作逆序一个栈
*/

#include <iostream>
#include <stack>

using namespace std;

int GetStackLastElement(stack<int> &stack)
{
	int curr_value = stack.top();
	stack.pop();
	if (stack.empty()) {
		return curr_value;
	} else {
		int last_value = GetStackLastElement(stack);
		stack.push(curr_value);
		return last_value;
	}
}

void ReverseStack(stack<int> &stack)
{
	if (stack.empty()) {
		return;
	}
	int last_value = GetStackLastElement(stack);
	ReverseStack(stack);
	stack.push(last_value);
}

int main()
{
	stack<int> my_stack({1,2,3,4,5});
	cout << my_stack.top() << endl;
	ReverseStack(my_stack);
	cout << my_stack.top() << endl;
	return 0;
}