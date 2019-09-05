class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {
		m_min_val = INT_MAX;
	}
	
	void push(int x) {
		m_data.push_back(x);
		if (x < m_min_val)
			m_min_val = x;
	}
	
	void pop() {
		if (m_data.empty())
			return;
		m_data.pop_back();
		SetMin();
	}
	
	int top() {
		if (m_data.empty())
			return -1;
		return m_data.back();
	}
	
	int getMin() {
		return m_min_val;
	}

private:
	int m_min_val;
	vector<int> m_data;

	void SetMin()
	{
		m_min_val = INT_MAX;
		for (auto e : m_data) {
			if (e < m_min_val)
				m_min_val = e;
		}
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */