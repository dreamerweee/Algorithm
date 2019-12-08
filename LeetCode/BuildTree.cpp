/*
* 根据一棵树的前序遍历与中序遍历构造二叉树
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
TreeNode *CreateNode(vector<int> &preorder, int pre_lt, int pre_rt,
					 vector<int> &inorder, int in_lt, int in_rt)
{
	if (pre_lt > pre_rt || in_lt > in_rt) {
		return nullptr;
	}

	TreeNode *node = new TreeNode(preorder[pre_lt]);
	int left_end = in_lt;
	for (; left_end <= in_rt; ++left_end) {
		if (inorder[left_end] == preorder[pre_lt]) {
			break;
		}
	}
	if (left_end != in_lt) {
		node->left = CreateNode(preorder, pre_lt + 1, pre_lt + left_end - in_lt, inorder, in_lt, left_end);
	}
	pre_lt += left_end - in_lt + 1;
	node->right = CreateNode(preorder, pre_lt, pre_rt, inorder, ++left_end, in_rt);
	return node;
}

TreeNode* BuildTree(vector<int>& preorder, vector<int>& inorder)
{
	return CreateNode(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
}