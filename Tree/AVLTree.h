#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
#include <climits>

/*
* 平衡二叉查找树的实现
*/

class AvlTree {
private:
	struct TreeNode {
		int m_value;
		int m_height;
		struct TreeNode *m_left;
		struct TreeNode *m_right;
		TreeNode(int val, struct TreeNode *left = nullptr, struct TreeNode *right = nullptr) :
			m_value(val), m_height(0), m_left(left), m_right(right) { }
	};

public:
	using NodeType = struct TreeNode;
	AvlTree() : m_root(nullptr) { }
	~AvlTree();

	NodeType* GetLeft(NodeType *node) const
	{
		return node->m_left;
	}
	NodeType* GetRight(NodeType *node) const
	{
		return node->m_right;
	}
	int GetValue(NodeType *node) const
	{
		if (node) {
			return node->m_value;
		}
		return INT_MIN;
	}

	bool Find(int val) const;
	bool Insert(int val);
	bool Delete(int val);

	void Print() const;

	int GetHeight() const
	{
		return GetHeight(m_root);
	}

private:
	NodeType *m_root;

	NodeType* Insert(NodeType *node, int val);
	NodeType* Delete(NodeType *node, int val);

	int Max(int a, int b)
	{
		return a > b ? a : b;
	}

	void Destroy(NodeType *node)
	{
		if (node == nullptr) {
			return;
		}
		Destroy(GetLeft(node));
		Destroy(GetRight(node));
		delete node;
	}

	int GetHeight(NodeType *node) const
	{
		if (node == nullptr) {
			return 0;
		} else {
			return node->m_height;
		}
	}

	void SetLeft(NodeType *node, NodeType *new_left)
	{
		node->m_left = new_left;
	}

	void SetRight(NodeType *node, NodeType *new_right)
	{
		node->m_right = new_right;
	}

	void UpdateHeight(NodeType *node)
	{
		node->m_height = Max(GetHeight(node->m_left), GetHeight(node->m_right)) + 1;
	}

	// 旋转
	/* 左子树高度比右子树高度大 单右旋*/
	NodeType* RightRotate(NodeType *node);
	/* 单左旋 */
	NodeType* LeftRotate(NodeType *node);
	/* 先左旋再右旋 */
	NodeType* LeftRightRotate(NodeType *node);
	/* 先右旋再左旋 */
	NodeType* RightLeftRotate(NodeType *node);

	void Print(std::ostream &out, NodeType *node) const
	{
		if (node) {
			out << node->m_value << " ";
		}
	}

	NodeType* Maximum(NodeType *node)
	{
		if (node == nullptr) {
			return nullptr;
		}
		while (node->m_right) {
			node = node->m_right;
		}
		return node;
	}

	NodeType* Minimum(NodeType *node)
	{
		if (node == nullptr) {
			return nullptr;
		}
		while (node->m_left) {
			node = node->m_left;
		}
		return node;
	}
};

#endif //AVL_TREE_H