#ifndef SKIPLIST_H
#define SKIPLIST_H

#define SKIP_LIST_MAX_LEVEL 10

#include <cstdlib>
#include <vector>

using std::vector;

class SkipListNode {
public:
	int m_key;
	int m_data;
	vector<SkipListNode*> m_forwards;

	SkipListNode(size_t level, int key, int data)
		: m_key(key), m_data(data), m_forwards(level, nullptr) { }
};

class SkipList {
public:
	SkipList();
	~SkipList();

	bool Insert(int key, int data);
	bool Delete(int key, int data);
	SkipListNode* Search(int key, int data) const;

	void PrintSkipList() const;

private:
	SkipListNode *m_head;

	static int RandLevel()
	{
		int k = 1;
		while (rand() % 2)
			++k;
		return (k < SKIP_LIST_MAX_LEVEL) ? k : SKIP_LIST_MAX_LEVEL;
	}
};

#endif //SKIPLIST_H