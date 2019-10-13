#include "AVLTree.h"
#include <stack>

using std::stack;

AvlTree::~AvlTree()
{
	Destroy(m_root);
}

bool AvlTree::Find(int val) const
{
	NodeType *curr = m_root;
	while (curr) {
		if (GetValue(curr) > val) {
			curr = GetLeft(curr);
		} else if (GetValue(curr) < val) {
			curr = GetRight(curr);
		} else {
			return true;
		}
	}
	return false;
}

bool AvlTree::Insert(int val)
{
	if (Find(val)) {
		std::cout << "AvlTree Insert val:" << val << " had exist." << std::endl;
		return false;
	}
	m_root = Insert(m_root, val);
	return true;
}

bool AvlTree::Delete(int val)
{
	if (!Find(val)) {
		std::cout << "AvlTree Delete val:" << val << " not find." << std::endl;
		return false;
	}
	m_root = Delete(m_root, val);
	return true;
}

// 返回旋转后的根节点
AvlTree::NodeType* AvlTree::RightRotate(NodeType *node)
{
	NodeType *curr = GetLeft(node);
	SetLeft(node, GetRight(curr));
	SetRight(curr, node);
	// 更新节点的高度
	UpdateHeight(node);
	UpdateHeight(curr);

	return curr;
}

AvlTree::NodeType* AvlTree::LeftRotate(NodeType *node)
{
	NodeType *curr = GetRight(node);
	SetRight(node, GetLeft(curr));
	SetLeft(curr, node);
	// 更新节点高度
	UpdateHeight(node);
	UpdateHeight(curr);

	return curr;
}

AvlTree::NodeType* AvlTree::LeftRightRotate(NodeType *node)
{
	NodeType *curr = LeftRotate(GetLeft(node));
	SetLeft(node, curr);
	return RightRotate(node);
}

AvlTree::NodeType* AvlTree::RightLeftRotate(NodeType *node)
{
	NodeType *curr = RightRotate(GetRight(node));
	SetRight(node, curr);
	return LeftRotate(node);
}

AvlTree::NodeType* AvlTree::Insert(NodeType *node, int val)
{
	if (node == nullptr) {
		node = new NodeType(val, nullptr, nullptr);
	} else if (val > GetValue(node)) {
		NodeType *curr = Insert(GetRight(node), val);
		SetRight(node, curr);
		// 平衡被破坏通过旋转恢复
		if (GetHeight(GetRight(node)) - GetHeight(GetLeft(node)) >= 2) {
			if (val > GetValue(GetRight(node))) {
				node = LeftRotate(node);
			} else {
				node = RightLeftRotate(node);
			}
		}
	} else if (val < GetValue(node)) {
		NodeType *curr = Insert(GetLeft(node), val);
		SetLeft(node, curr);
		if (GetHeight(GetLeft(node)) - GetHeight(GetRight(node)) >= 2) {
			if (val < GetValue(GetLeft(node))) {
				node = RightRotate(node);
			} else {
				node = LeftRightRotate(node);
			}
		}
	} else {
		std::cout << "AvlTree Insert val had exist." << std::endl;
	}
	
	UpdateHeight(node);
	return node;
}

AvlTree::NodeType* AvlTree::Delete(NodeType *node, int val)
{
	if (node == nullptr) {
		return nullptr;
	}

	if (val < GetValue(node)) { // 待删除节点在左子树中
		NodeType *curr = Delete(GetLeft(node), val);
		SetLeft(node, curr);
		if (GetHeight(GetRight(node)) - GetHeight(GetLeft(node)) == 2) {
			// 如果node节点的右节点的左高度大于右高度，则先右旋再左旋node节点
			NodeType *r = GetRight(node);
			if (GetHeight(GetLeft(r)) > GetHeight(GetRight(r))) {
				node = RightLeftRotate(node);
			} else {
				node = LeftRotate(node);
			}
		}
	} else if (val > GetValue(node)) { // 待删除节点在右子树中
		NodeType *curr = Delete(GetRight(node), val);
		SetRight(node, curr);
		if (GetHeight(GetLeft(node)) - GetHeight(GetRight(node)) == 2) {
			NodeType *l = GetLeft(node);
			if (GetHeight(GetRight(l)) > GetHeight(GetLeft(l))) {
				node = LeftRightRotate(node);
			} else {
				node = RightRotate(node);
			}
		}
	} else {  // 删除当前节点
		if (GetLeft(node) && GetRight(node)) {
			if (GetHeight(GetLeft(node)) > GetHeight(GetRight(node))) {
				NodeType *max = Maximum(GetLeft(node));
				node->m_value = GetValue(max);
				SetLeft(node, Delete(GetLeft(node), GetValue(max)));
			} else {
				NodeType *min = Minimum(GetRight(node));
				node->m_value = GetValue(min);
				SetRight(node, Delete(GetRight(node), GetValue(min)));
			}
		} else {
			NodeType *temp = node;
			node = (GetLeft(node) != nullptr) ? GetLeft(node) : GetRight(node);
			delete temp;
		}
	}

	return node;
}

void AvlTree::Print() const
{
	if (m_root == nullptr) {
		std::cout << "empty AvlTree" << std::endl;
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
