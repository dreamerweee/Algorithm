/*
* 编写一个类，用两个栈实现队列，支持队列的基本操作
*/

#include <vector>
#include <iostream>

using namespace std;

class StackQueue {
public:
	StackQueue() = default;
	~StackQueue() = default;

	void Enqueue(int value);
	int Dequeue();
	void Print() const;
	bool Empty() const
	{
		return m_stack_push.empty() && m_stack_pop.empty();
	}

private:
	vector<int> m_stack_push;
	vector<int> m_stack_pop;
};

void StackQueue::Enqueue(int value)
{
	m_stack_push.push_back(value);
}

int StackQueue::Dequeue()
{
	if (Empty()) {
		cout << "StackQueue is empty." << endl;
		return -1;
	}

	if (m_stack_pop.empty()) {
		auto rbeg = m_stack_push.rbegin();
		while (rbeg != m_stack_push.rend()) {
			m_stack_pop.push_back(*rbeg++);
		}
		m_stack_push.clear();
	}
	int value = m_stack_pop.back();
	m_stack_pop.pop_back();
	return value;
}

void StackQueue::Print() const
{
	if (Empty()) {
		cout << "Empty StackQueue." << endl;
		return;
	}

	cout << "StackQueue data: ";
	if (!m_stack_pop.empty()) {
		auto crbeg = m_stack_pop.crbegin();
		while (crbeg != m_stack_pop.rend()) {
			cout << *crbeg++ << " ";
		}
	}
	if (!m_stack_push.empty()) {
		auto cbeg = m_stack_push.cbegin();
		while (cbeg != m_stack_push.cend()) {
			cout << *cbeg++ << " ";
		}
	}
	cout << endl;
}

int main()
{
	StackQueue my_stack_queue;
	my_stack_queue.Print();
	int value;
	while (cin >> value) {
		my_stack_queue.Enqueue(value);
	}
	my_stack_queue.Print();
	my_stack_queue.Dequeue();
	my_stack_queue.Print();
	my_stack_queue.Enqueue(10);
	my_stack_queue.Print();
	my_stack_queue.Dequeue();
	my_stack_queue.Dequeue();
	my_stack_queue.Dequeue();
	my_stack_queue.Dequeue();
	my_stack_queue.Print();

	return 0;
}