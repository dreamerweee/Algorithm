/*
* 给定两个二叉树，编写一个函数来检验它们是否相同。
* 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool IsSameTree(TreeNode* p, TreeNode* q)
{
	if (!p && !q) {
		return true;
	} else if ((!p && q) || (p && !q)) {
		return false;
	}

	if (p->val != q->val) {
		return false;
	} else {
		if (IsSameTree(p->left, q->left)) {
			return IsSameTree(p->right, q->right);
		} else {
			return false;
		}
	}
}