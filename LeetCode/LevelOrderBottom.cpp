/*
* 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
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
vector<vector<int>> LevelOrderBottom(TreeNode* root)
{
	if (!root)
		return {};
	stack<vector<TreeNode*>> stk;
	stk.push({root});
	vector<vector<int>> positive_seq;
	while (!stk.empty()) {
		auto curr_vec = stk.top();
		stk.pop();
		vector<TreeNode*> node_vec;
		vector<int> val_vec;
		for (auto node : curr_vec) {
			val_vec.push_back(node->val);
			if (node->left)
				node_vec.push_back(node->left);
			if (node->right)
				node_vec.push_back(node->right);
		}
		if (!val_vec.empty())
			positive_seq.push_back(val_vec);
		if (!node_vec.empty())
			stk.push(node_vec);
	}

	vector<vector<int>> result(positive_seq.rbegin(), positive_seq.rend());
	return result;
}