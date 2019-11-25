/*
* 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
* 获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
* 写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。
* 当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。

* 进阶:
*   你是否可以在 O(1) 时间复杂度内完成这两种操作？
*/

class LRUCache {
private:
	typedef struct Node {
		int m_value;
		struct Node *m_next;
		struct Node *m_prev;

		Node(int value, struct Node *next, struct Node *prev)
			: m_value(value), m_next(next), m_prev(prev)
		{ }
	} Node;

	void UpdateList(Node *node)
	{
		if (node == m_head->m_next) {
			return;
		}
		Node *prev = node->m_prev;
		Node *next = node->m_next;
		prev->m_next = next;
		next->m_prev = prev;

		next = m_head->m_next;
		m_head->m_next = node;
		node->m_prev = m_head;
		node->m_next = next;
	}

	void DeleteLast()
	{
		Node *last = m_tail->m_prev;
		Node *prev = last->m_prev;
		prev->m_next = m_tail;
		m_tail->m_prev = prev;
		delete last;
	}

	void InsertHead(Node *node)
	{
		Node *next = m_head->m_next;
		m_head->m_next = node;
		next->m_prev = node;
		node->m_prev = m_head;
		node->m_next = next;
	}

public:
	LRUCache(int capacity)
		: m_capacity(capacity), m_head(new Node(-1, nullptr, nullptr)), m_tail(new Node(-1, nullptr, nullptr))
	{
		m_head->m_next = m_tail;
		m_tail->m_prev = m_head;
	}
	~LRUCache()
	{
		while (m_head) {
			Node *cur = m_head;
			m_head = m_head->m_next;
			delete cur;
		}
	}

	int get(int key) {
		int value = -1;
		auto search = m_data.find(key);
		if (search != m_data.end()) {
			value = search->second->value;
			UpdateList(search->second);
		}
		return value;
	}

	void put(int key, int value) {
		auto search = m_data.find(key);
		if (search != m_data.end()) {
			return;
		}

		if (m_size >= m_capacity) {
			DeleteLast();
		}

		Node *new_node = new Node(value, nullptr, nullptr);
		m_data[key] = new_node;
		InsertHead(new_node)
		++m_size;
	}

private:
	int m_capacity;
	int m_size;
	Node *m_head;
	Node *m_tail;
	std::unordered_map<int, Node*> m_data;
};