#include <iostream>
#include <stack>

using namespace std;

const int kMaxStackSize = 10;

class Stack {
public:
    void Push(int val);
    void Pop();
    int Top() const;
    int GetMin() const;
    bool Empty() const;
private:
    stack<int> m_data;
    stack<int> m_min;
};

void Stack::Push(int val)
{
    if (m_min.empty()) {
        m_min.push(val);
    } else {
        if (m_min.top() >= val) {
            m_min.push(val);
        }
    }
    m_data.push(val);
}

int Stack::Top() const
{
    if (m_data.empty()) {
        throw runtime_error("Top Empty Stack.");
    }
    return m_data.top();
}

bool Stack::Empty() const
{
    return m_data.empty();
}

void Stack::Pop()
{
    if (m_data.empty()) {
        throw runtime_error("Pop Empty Stack.");
    }
    int val = Top();
    m_data.pop();
    if (m_min.top() == val) {
        m_min.pop();
    }
}

int Stack::GetMin() const
{
    if (m_min.empty()) {
        throw runtime_error("GetMin Empty Stack.");
    }
    return m_min.top();
}

int main(void)
{
    Stack my_stack;
    int val;
    while (cin >> val) {
        my_stack.Push(val);
    }
    while (!my_stack.Empty()) {
        cout << "min = " << my_stack.GetMin();
        cout << " current val = " << my_stack.Top() << endl;
        my_stack.Pop();
    }

    return 0;
}