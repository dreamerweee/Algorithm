#include "BinarySearchTree.h"
#include <stack>

using std::stack;

bool BinarySearchTree::Insert(int value)
{
	if (m_root == nullptr) {
		m_root = new NodeType(value);
		return true;
	}
	NodeType *curr = m_root;
	while (curr) {
		if (curr->m_value > value) {
			if (GetLeft(curr) == nullptr) {
				NodeType *new_node = new NodeType(value);
				SetLeft(curr, new_node);
				return true;
			}
			curr = GetLeft(curr);
		} else if (curr->m_value < value) {
			if (GetRight(curr) == nullptr) {
				NodeType *new_node = new NodeType(value);
				SetRight(curr, new_node);
				return true;
			}
			curr = GetRight(curr);
		} else {
			return false;  // 已存在
		}
	}

	return false;
}

bool BinarySearchTree::Delete(int value)
{
	if (m_root == nullptr) {
		return false;
	}
	NodeType *parent = nullptr, *del = m_root;
	while (del && del->m_value != value) {
		parent = del;
		if (value < del->m_value) {
			del = GetLeft(del);
		} else if (value > del->m_value) {
			del = GetRight(del);
		}
	}
	if (del == nullptr) {
		return false;
	}

	NodeType *pl = GetLeft(del);
	NodeType *pr = GetRight(del);
	if (pl && pr) {
		NodeType *pr_min = pr;
		NodeType *pr_parent = del;
		while (GetLeft(pr_min)) {
			pr_parent = pr_min;
			pr_min = GetLeft(pr_min);
		}
		del->m_value = pr_min->m_value;
		del = pr_min;
		parent = pr_parent;
	}

	NodeType *child = nullptr;
	if (GetLeft(del)) {
		child = GetLeft(del);
	} else if (GetRight(del)) {
		child = GetRight(del);
	}

	if (parent == nullptr) {
		m_root = child;
	} else if (GetLeft(parent) == del) {
		SetLeft(parent, child);
	} else {
		SetRight(parent, child);
	}

	delete del;

	return true;
}

BinarySearchTree::NodeType* BinarySearchTree::Search(int value) const
{
	NodeType *cursor = m_root;
	while (cursor) {
		if (value < cursor->m_value) {
			cursor = GetLeft(cursor);
		} else if (value > cursor->m_value) {
			cursor = GetRight(cursor);
		} else {
			break;
		}
	}
	return cursor;
}

void BinarySearchTree::PreOrderPrint() const
{
	if (m_root == nullptr) {
		return;
	}
	stack<NodeType*> stk;
	stk.push(m_root);
	NodeType *curr = nullptr;
	while (!stk.empty()) {
		curr = stk.top();
		stk.pop();
		if (curr) {
			Print(std::cout, curr);
			stk.push(GetRight(curr));
			stk.push(GetLeft(curr));
		}
	}
	std::cout << std::endl;
}

void BinarySearchTree::InOrderPrint() const
{
	if (m_root == nullptr) {
		return;
	}
	stack<NodeType*> stk;
	NodeType *curr = m_root;
	do {
		while (curr) {
			stk.push(curr);
			curr = GetLeft(curr);
		}

		if (!stk.empty()) {
			curr = stk.top();
			stk.pop();
			Print(std::cout, curr);
			curr = GetRight(curr);
		}
	} while (!stk.empty() || curr);
	std::cout << std::endl;
}

void BinarySearchTree::PostOrderPrint() const
{
	if (m_root == nullptr) {
		return;
	}
	stack<NodeType*> stk;
	NodeType *curr = m_root;
	do {
		while (curr) {
			stk.push(curr);
			curr = GetLeft(curr);
		}

		NodeType *right = nullptr;
		while (!stk.empty()) {
			curr = stk.top();
			if (GetRight(curr) == right) {
				stk.pop();
				Print(std::cout, curr);
				right = curr;
			} else {
				curr = GetRight(curr);
				break;
			}
		}
	} while (!stk.empty());
	std::cout << std::endl;
}
