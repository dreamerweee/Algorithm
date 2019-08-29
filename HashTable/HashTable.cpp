#include <algorithm>
#include "HashTable.h"

HashTable::HashTable(size_t size)
{
	m_ht.reserve(size);
	m_ht.resize(size);
}

bool HashTable::Insert(int value)
{
	if (Find(value)) {
		return false;
	}

	size_t hash_val = Hash(value);
	list<int> &lt = m_ht[hash_val];
	lt.push_back(value);
	return true;
}

bool HashTable::Remove(int value)
{
	size_t hash_val = Hash(value);
	list<int> &lt = m_ht[hash_val];
	auto it = find(lt.begin(), lt.end(), value);
	if (it == lt.end()) {
		return false;
	}
	lt.erase(it);
	return true;
}

bool HashTable::Find(int value) const
{
	size_t hash_val = Hash(value);
	const list<int> &lt = m_ht[hash_val];

	list<int>::const_iterator it = lt.cbegin();
	for (; it != lt.cend() && *it != value; ++it)
		;

	if (it != lt.cend()) {
		return true;
	}
	else {
		return false;
	}
}

size_t HashTable::Hash(int value) const
{
	return value % m_ht.size();
}