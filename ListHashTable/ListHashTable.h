/*
* 结合双向链表和哈希表实现的LRU缓存淘汰算法
* 插入/删除/查找的时间复杂度达到O(k)，k为缓存因子等于hashtable已有的元素个数除以最大能存储的元素个数。
*/

#ifndef LISTHASHTABLE_H
#define LISTHASHTABLE_H

#include <unordered_map>

// 删除时从头部删除，最新的插入尾部
class ListHashTable {
public:
	// 数据信息
	typedef struct HashNode {
		int m_data; 		// 数据，hash的依据
		struct HashNode *m_list_prev;
		struct HashNode *m_list_next;
		HashNode(int value = 0, struct HashNode *prev = nullptr, struct HashNode *next = nullptr) :
			m_data(value), m_list_prev(prev), m_list_next(next)
		{ }
	}HashNode;

	ListHashTable();
	~ListHashTable();

	HashNode* Find(int value) const;
	bool Insert(int value);
	bool Delete(int value);
	void Print() const;

private:
	void PushBack(HashNode *node);  // 将结点放到尾部
	void PopFront();
	
	std::unordered_map<int, HashNode*> m_hash_table;
	HashNode *m_head;  // list的头结点
	HashNode *m_tail;  // list的尾结点
};

#endif //LISTHASHTABLE_H