// 实现一个大小固定的有序数组，支持动态增删改操作

#ifndef ARRAY_H_
#define ARRAY_H_

#include <cstdlib>
#include <stdexcept>

class Array {
public:
	explicit Array(size_t len) : m_size(0), m_maxlen(len)
	{
		m_data = new int[len]();
	}
	~Array()
	{
		delete [] m_data;
	}

	void Insert(const int value);
	void Delete(const size_t idx);  // 删除idx位置上的元素
	void Update(const size_t idx, const int new_value);
	void Print() const;

	size_t GetSize() const
	{
		return m_size;
	}

	int& operator[](size_t idx) const
	{
		if (idx >= m_size)
			throw std::out_of_range("Index out of range!");
		return m_data[idx];
	}

private:
	int *m_data;
	size_t m_size;
	size_t m_maxlen;
};

#endif //ARRAY_H_