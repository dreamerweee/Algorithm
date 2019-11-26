/*
* 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
* 假设一个二叉搜索树具有如下特征：
*	节点的左子树只包含小于当前节点的数。
*	节点的右子树只包含大于当前节点的数。
*	所有左子树和右子树自身必须也是二叉搜索树。
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
bool IsValidBST(TreeNode *root, int *lower, int *upper)
{
	if (!root) {
		return true;
	}

	int val = root->val;
	if (lower && val <= *lower) {
		return false;
	}
	if (upper && val >= *upper) {
		return false;
	}
	if (!IsValidBST(root->left, lower, &val)) {
		return false;
	}
	if (!IsValidBST(root->right, &val, upper)) {
		return false;
	}

	return true;
}

bool IsValidBST(TreeNode* root)
{
	return IsValidBST(root, nullptr, nullptr);
}

//leetcode 解法
bool isValidBST(TreeNode* root) 
{
	if(root == NULL)
		return true;
	if(root->left == NULL && root->right == NULL)
		return true;
	TreeNode* leftmax=root->left;
	while(leftmax&&leftmax->right)
		leftmax=leftmax->right;
	TreeNode* rightmin=root->right;
	while(rightmin&&rightmin->left)
		rightmin=rightmin->left;
	
	if(leftmax&&(leftmax->val>=root->val))
		return false;
	if(rightmin&&(rightmin->val<=root->val))
		return false;

	return isValidBST(root->left)&&isValidBST(root->right);
}