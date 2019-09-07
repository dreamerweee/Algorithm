#include "SkipList.h"
#include <iostream>

using namespace std;

SkipList::SkipList()
{
	m_head = new SkipListNode(SKIP_LIST_MAX_LEVEL, 0, 0);
}

SkipList::~SkipList()
{
	SkipListNode *curr = m_head;
	while (curr) {
		SkipListNode *temp = curr;
		curr = curr->m_forwards[0];
		delete temp;
	}
}

bool SkipList::Insert(int key, int data)
{
	SkipListNode *update[SKIP_LIST_MAX_LEVEL];
	int i = SKIP_LIST_MAX_LEVEL - 1;
	SkipListNode *cursor = m_head;
	for (; i >= 0; --i) {
		while (cursor->m_forwards[i] && 
			  (cursor->m_forwards[i]->m_key < key || 
			  (cursor->m_forwards[i]->m_key == key && 
			   cursor->m_forwards[i]->m_data < data))) {
			cursor = cursor->m_forwards[i];
		}
		update[i] = cursor;
	}
	if (cursor && cursor->m_key == key && cursor->m_data == data) {
		return false;  // 已存在相同key和value的数据
	}

	int level = RandLevel();
	SkipListNode *new_node = new SkipListNode(level, key, data);
	for (i = 0; i < level; ++i) {
		new_node->m_forwards[i] = update[i]->m_forwards[i];
		update[i]->m_forwards[i] = new_node;
	}

	return true;
}

bool SkipList::Delete(int key, int data)
{
	SkipListNode *update[SKIP_LIST_MAX_LEVEL];
	int i = SKIP_LIST_MAX_LEVEL - 1;
	SkipListNode *cursor = m_head, *p = nullptr;
	for (; i >= 0; --i) {
		while ((p = cursor->m_forwards[i]) && 
			  (p->m_key < key || (p->m_key == key && p->m_data < data))) {
			cursor = p;
		}
		update[i] = cursor;
	}
	if (p && (p->m_key != key || p->m_data != data)) {
		return false;  // 不存在相同key和value的数据
	}
	for (i = 0; i < SKIP_LIST_MAX_LEVEL; ++i) {
		if (update[i]->m_forwards[i] == p) {
			update[i]->m_forwards[i] = p->m_forwards[i];
		}
	}
	delete p;

	return true;
}

SkipListNode* SkipList::Search(int key, int data) const
{
	SkipListNode *cursor = m_head, *p = nullptr;
	int i = SKIP_LIST_MAX_LEVEL - 1;
	for (; i >= 0; --i) {
		while ((p = cursor->m_forwards[i]) && 
			  (p->m_key < key || (p->m_key == key && p->m_data != data))) {
			cursor = p;
		}
		if (p && p->m_key == key && p->m_data == data) {
			return p;
		}
	}
	return nullptr;
}

void SkipList::PrintSkipList() const
{
	SkipListNode *curr = nullptr;
	int i = SKIP_LIST_MAX_LEVEL - 1;
	for (; i >= 0; --i) {
		curr = m_head;
		while (curr) {
			cout << "key = " << curr->m_key << ", data = " << curr->m_data << "; ";
			curr = curr->m_forwards[i];
		}
		cout << endl;
	}
	cout << endl;
}
