#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <stdexcept>

// 实现一个支持动态扩容的数组
// 先不实现为模板类，实现为一个int的动态数组

class DynamicArray {
public:
	DynamicArray(size_t len = 1) : m_capacity(len), m_size(0)
	{
		m_head = new int[m_capacity]();
	}
	~DynamicArray()
	{
		delete [] m_head;
	}

	int& operator[](size_t idx) const
	{
		if (idx >= m_size)
			throw std::out_of_range("Index out of range!");
		return m_head[idx];
	}

	size_t GetSize() const
	{
		return m_size;
	}

	bool Insert(size_t idx, int value);
	bool Delete(size_t idx);
	void Print() const;

private:
	void Resize(size_t new_cap);

	int *m_head; 		// 指向第一个元素
	size_t m_capacity;  // 数组最大容量
	size_t m_size; 		// 当前元素数量
};

#endif //DYNAMICARRAY_H