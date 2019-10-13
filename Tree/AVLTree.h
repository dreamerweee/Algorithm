#ifndef AVL_TREE_H
#define AVL_TREE_H

/*
* 平衡二叉查找树的实现
*/

class AvlTree {
private:
	struct TreeNode {
		int m_value;
		struct TreeNode *m_left;
		struct TreeNode *m_right;
		TreeNode(int val, struct TreeNode *left = nullptr, struct TreeNode *right = nullptr) :
			m_value(val), m_left(left), m_right(right) { }
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

private:
	NodeType *m_root;

	void Destroy(NodeType *node)
	{
		if (node == nullptr) {
			return;
		}
		Destroy(GetLeft(node));
		Destroy(GetRight(node));
		delete node;
	}
};

#endif //AVL_TREE_H