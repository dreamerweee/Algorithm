// 实现一个大小固定的有序数组，支持动态增删改操作

#ifndef ARRAY_H_
#define ARRAY_H_

class Array {
public:
	explicit Array(size_t len) : m_data(new int[len]), m_maxlen(len) { }
	~Array()
	{
		delete [] m_data;
	}

	void Insert(const int value);
	void Delete(const size_t idx);  // 删除idx位置上的元素
	void Update(const size_t idx, const int new_value);
	void Print() const;

private:
	int *m_data;
	size_t m_size = 0;
	size_t m_maxlen;
};

#endif //ARRAY_H_