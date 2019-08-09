#include "Array.h"
#include <iostream>

using std::cout;
using std::endl;

void Array::Insert(const int value)
{
	if (m_size >= m_maxlen) {
		cout << "This Array is full." << endl;
		return ;
	}

	// 查找插入位置，可改用二分法查找
	size_t ins_idx = 0;
	for (; ins_idx < m_size; ++ins_idx) {
		if (m_data[ins_idx] > value)
			break;
	}

	// 插入数据
	for (size_t i = m_size; i > ins_idx; --i) {
		m_data[i] = m_data[i - 1];
	}
	m_data[ins_idx] = value;
	++m_size;
}

void Array::Delete(const size_t idx)
{
	if (idx >= m_size) {
		cout << "Delete Array idx:" << idx << " out of range." << endl;
		return ;
	}
	for (size_t i = idx; i < m_size - 1; ++i)
		m_data[i] = m_data[i + 1];
	--m_size;
}

// 更新值后保持数组有序
void Array::Update(const size_t idx, const int new_value)
{
	if (idx >= m_size) {
		cout << "Update Array idx:" << idx << " out of range." << endl;
		return ;
	}
	size_t new_idx = idx;
	if ((idx - 1 < idx) && (m_data[idx-1] > new_value)) {  // 新值变小，往前移动
		for (; new_idx > 0; --new_idx) {
			if (m_data[new_idx - 1] > new_value)
				m_data[new_idx] = m_data[new_idx - 1];
			else
				break;
		}
	} else if ((idx + 1 < m_size) && (m_data[idx+1] < new_value)) {  // 新值变大，往后移动
		for (; new_idx < m_size - 1; ++new_idx) {
			if (m_data[new_idx+1] > new_value)
				m_data[new_idx] = m_data[new_idx+1];
			else
				break;
		}
	}
	// else 其他情况则为值变了，但是位置不会变
	
	m_data[new_idx] = new_value;
}

void Array::Print() const
{
	if (m_size == 0) {
		cout << "This Array is Empty." << endl;
		return ;
	}
	for (size_t i = 0; i < m_size; ++i)
		cout << m_data[i] << " ";
	cout << endl;
}