/*
* 给定一个二叉树，找出其最大深度。
* 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
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

int MaxDepth(TreeNode* root)
{
	if (root == nullptr) {
		return 0;
	}
	int deep_l = MaxDepth(root->left);
	int deep_r = MaxDepth(root->right);
	if (deep_l > deep_r) {
		return 1 + deep_l;
	} else {
		return 1 + deep_r;
	}
}