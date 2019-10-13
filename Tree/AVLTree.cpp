#include "AVLTree.h"

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

}

bool AvlTree::Delete(int val)
{

}
