// 实现一个基于链表法解决冲突问题的散列表

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <list>
#include <cstddef>

using std::vector;
using std::list;

class HashTable {
public:
	HashTable(size_t size = 10);
	~HashTable() { }

	bool Insert(int value);
	bool Remove(int value);
	bool Find(int value) const;

private:
	vector<list<int>> m_ht;
	size_t Hash(int value) const;
};

#endif //HASHTABLE_H