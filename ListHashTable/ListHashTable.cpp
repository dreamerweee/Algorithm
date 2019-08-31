#include <iostream>
#include "ListHashTable.h"

using namespace std;

ListHashTable::ListHashTable()
{
	m_head = new HashNode();
	m_tail = new HashNode();
	m_head->m_list_next = m_tail;
	m_tail->m_list_prev = m_head;
}

ListHashTable::~ListHashTable()
{
	HashNode *cur = m_head->m_list_next;
	while (cur != m_tail) {
		HashNode *n = cur;
		cur = cur->m_list_next;
		delete n;
	}
	delete m_head;
	delete m_tail;
}

ListHashTable::HashNode* ListHashTable::Find(int value) const
{
	auto itr = m_hash_table.find(value);
	if (itr == m_hash_table.end())
		return nullptr;
	else
		return itr->second;
}

bool ListHashTable::Insert(int value)
{
	HashNode *cur = Find(value);
	if (cur) {
		PushBack(cur);
	} else {
		cur = new HashNode(value);
		// 插入hash表
		m_hash_table.insert({value, cur}); 
	}
	// 更新链表中的位置
	PushBack(cur);
	return true;
}

bool ListHashTable::Delete(int value)
{
	HashNode *cur = Find(value);
	if (cur) {
		HashNode *cur_prev = cur->m_list_prev;
		HashNode *cur_next = cur->m_list_next;
		cur_prev->m_list_next = cur_next;
		cur_next->m_list_prev = cur_prev;
		delete cur;
		return true;
	}
	return false;
}

void ListHashTable::PushBack(HashNode *node)
{
	if (node->m_list_next != m_tail) {
		// 从当前结点脱离
		if (node->m_list_prev && node->m_list_next) {
			HashNode *node_prev = node->m_list_prev;
			HashNode *node_next = node->m_list_next;
			node_prev->m_list_next = node_next;
			node_next->m_list_prev = node_prev;
		}

		// 插入到最后
		HashNode *t_prev = m_tail->m_list_prev;
		t_prev->m_list_next = node;
		node->m_list_next = m_tail;
		node->m_list_prev = t_prev;
		m_tail->m_list_prev = node;
	}
}

void ListHashTable::PopFront()
{
	HashNode *del = m_head->m_list_next;
	if (del && del != m_tail) {
		m_head->m_list_next = del->m_list_next;
		del->m_list_next->m_list_prev = m_head;
		delete del;
	}
}

void ListHashTable::Print() const
{
	HashNode *cur = m_head->m_list_next;
	while (cur != m_tail) {
		cout << cur->m_data << " ";
		cur = cur->m_list_next;
	}
}