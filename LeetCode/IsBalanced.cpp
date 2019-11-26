/*
* 给定一个二叉树，判断它是否是高度平衡的二叉树。
* 本题中，一棵高度平衡二叉树定义为：
*   一个二叉树每个节点的左右两个子树的高度差的绝对值不超过1。
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

inline int SubAbs(int a, int b)
{
	if (a > b) {
		return a - b;
	} else {
		return b - a;
	}
}

int GetHeight(TreeNode *node)
{
	if (!node) {
		return 0;
	}
	int left_height = GetHeight(node->left);
	if (left_height < 0) {
		return -1;
	}
	int right_height = GetHeight(node->right);
	if (right_height < 0) {
		return -1;
	}

	if (SubAbs(left_height, right_height) < 2) {
		return (left_height > right_height ? left_height + 1 : right_height + 1);
	} else {
		return -1;
	}
}

bool IsBalanced(TreeNode* root)
{
	return GetHeight(root) >= 0;
}