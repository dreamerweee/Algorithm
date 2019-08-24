#include "DynamicArray.h"
#include <iostream>

using std::cout;
using std::endl;

bool DynamicArray::Insert(size_t idx, int value)
{
	if (idx > m_size) {
		cout << "DynamicArray: Insert: " << idx << " out of size." << endl;
		return false;
	}
	if (m_size + 1 >= m_capacity)
		Resize(m_capacity * 2);

	size_t ins_pos = m_size;
	for (; ins_pos > idx; --ins_pos) {
		m_head[ins_pos] = m_head[ins_pos - 1];
	}
	m_head[ins_pos] = value;
	++m_size;

	return true;
}

bool DynamicArray::Delete(size_t idx)
{
	if (idx >= m_size) {
		cout << "DynamicArray: Delete: " << idx << " out of size." << endl;
		return false;
	}

	for (size_t i = idx; i < m_size - 1; ++i)
		m_head[i] = m_head[i + 1];

	--m_size;

	return true;
}

void DynamicArray::Resize(size_t new_cap)
{
	if (new_cap <= m_capacity)
		cout << "DynamicArray: Resize: " << new_cap << " less than old: " << m_capacity << endl;
	else {
		int *new_head = new int[new_cap]();
		int *p = new_head;
		for (int *q = m_head; q != m_head + m_size; ++q) {
			*p = *q;
			++p;
		}
		delete [] m_head;
		m_head = nullptr;
		m_head = new_head;
		m_capacity = new_cap;
	}
}

void DynamicArray::Print() const
{
	if (m_size == 0 )
		cout << "DynamicArray: Print: empty array." << endl;
	else {
		for (size_t i = 0; i < m_size; ++i)
			cout << m_head[i] << " ";
		cout << endl;
	}
}