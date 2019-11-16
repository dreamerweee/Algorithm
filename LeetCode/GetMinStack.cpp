/*
* 实现一个特殊的栈，在实现栈的基本功能的基础上，再实现返回栈中最小元素的操作
* 要求：pop、push、GetMin操作的事件复杂度都是O(1)
*/

/*
* 实现：利用两个栈，一个保存正常的栈元素，另一个保存当前栈的最小值
*/
#include <vector>
#include <iostream>
using std::vector;
using std::cin;
using std::cout;
using std::endl;

class GetMinStack {
public:
	GetMinStack() = default;
	~GetMinStack() = default;

	void Pop();
	void Push(int value);
	int GetMin() const;
	void Print() const;

private:
	vector<int> m_data;
	vector<int> m_min_data;
};

void GetMinStack::Pop()
{
	if (m_data.size() == 0) {
		return;
	}
	int value = m_data.back();
	if (m_min_data.size() > 0) {
		if (value == m_min_data.back()) {
			m_min_data.pop_back();
		}
	}
	m_data.pop_back();
}

void GetMinStack::Push(int value)
{
	m_data.push_back(value);

	vector<int>::size_type len = m_min_data.size();
	if (len == 0) {
		m_min_data.push_back(value);
	} else {
		if (value <= m_min_data.back()) {
			m_min_data.push_back(value);
		}
	}
}

int GetMinStack::GetMin() const
{
	if (m_min_data.empty()) {
		return -1;
	} else {
		return m_min_data.back();
	}
}

void GetMinStack::Print() const
{
	if (!m_data.empty()) {
		cout << "stack data: ";
		for (auto e : m_data) {
			cout << e << " ";
		}
		cout << endl;

		if (!m_min_data.empty()) {
			cout << "min stack data: ";
			for (auto e : m_min_data) {
				cout << e << " ";
			}
			cout << endl;
		}
	}
}

int main()
{
	GetMinStack my_stack;
	int value;
	while (cin >> value) {
		my_stack.Push(value);
	}
	my_stack.Print();

	my_stack.Pop();
	my_stack.Print();
	my_stack.Pop();
	my_stack.Print();

	return 0;
}