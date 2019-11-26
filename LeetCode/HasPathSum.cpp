/*
* 给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
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
bool HasPathSum(TreeNode* root, int sum)
{
	if (!root) {
		return false;
	}

	if (!root->left && !root->right) {
		return sum == root->val;
	}

	return HasPathSum(root->left, sum - root->val) || HasPathSum(root->right, sum - root->val);
}
