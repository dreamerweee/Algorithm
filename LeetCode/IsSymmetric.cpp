/*
给定一个二叉树，检查它是否是镜像对称的。
例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
    1
   / \
  2   2
 / \ / \
3  4 4  3

但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
    1
   / \
  2   2
   \   \
   3    3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/symmetric-tree
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

bool IsSymmetric(TreeNode *left, TreeNode *right)
{
	if (!left && !right) {
		return true;
	}
	if ((!left && right) || (left && !right)) {
		return false;
	}
	if (left->val == right->val) {
		if (IsSymmetric(left->left, right->right)) {
			return IsSymmetric(left->right, right->left);
		} else {
			return false;
		}
	} else {
		return false;
	}
}

// 递归法求解
bool IsSymmetric(TreeNode *root)
{
	return IsSymmetric(root, root);
}