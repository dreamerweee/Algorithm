/*
* 给定一个二叉树，找出其最小深度。
* 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
* 说明: 叶子节点是指没有子节点的节点。
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
int MinDepth(TreeNode* root)
{
	if (!root) {
		return 0;
	}
	int left_depth = MinDepth(root->left);
	int right_depth = MinDepth(root->right);
	if (!root->left || !root->right) {
		return left_depth + right_depth + 1;
	}
	return 1 + min(left_depth, right_depth);
}