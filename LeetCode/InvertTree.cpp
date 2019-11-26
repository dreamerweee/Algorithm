// 翻转一棵二叉树

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* InvertTree(TreeNode* root)
{
	if (!root)
		return nullptr;
	if (root->left)
		InvertTree(root->left);
	if (root->right)
		InvertTree(root->right);
	if (!root->left && !root->right)
		return root;
	TreeNode *temp = root->left;
	root->left = root->right;
	root->right = temp;

	return root;
}