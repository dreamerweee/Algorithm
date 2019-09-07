#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>

class BinarySearchTree {
private:
	struct TreeNode {
		int m_value;
		struct TreeNode *m_left;
		struct TreeNode *m_right;
		TreeNode(int value, struct TreeNode *left = nullptr, struct TreeNode *right = nullptr) :
			m_value(value), m_left(left), m_right(right) { }
	};

public:
	using NodeType = struct TreeNode;
	BinarySearchTree() : m_root(nullptr) { }
	~BinarySearchTree()
	{
		Destory(m_root);
	}

	bool Insert(int value);
	bool Delete(int value);
	NodeType* Search(int value) const;
	void PreOrderPrint() const;
	void InOrderPrint() const;
	void PostOrderPrint() const;

	NodeType* GetLeft(NodeType *node) const
	{
		return node->m_left;
	}
	NodeType* GetRight(NodeType *node) const
	{
		return node->m_right;
	}

	void SetLeft(NodeType *node, NodeType *new_node)
	{
		node->m_left = new_node;
	}
	void SetRight(NodeType *node, NodeType *new_node)
	{
		node->m_right = new_node;
	}

private:
	NodeType *m_root;

	void Print(std::ostream &out, NodeType *node) const
	{
		if (node) {
			out << node->m_value << " ";
		}
	}

	void Destory(NodeType *root)
	{
		if (root == nullptr) {
			return;
		}
		Destory(GetLeft(root));
		Destory(GetRight(root));
		delete root;
	}
};

#endif //BINARYSEARCHTREE_H