/*
* 给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
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
vector<vector<int>> LevelOrder(TreeNode* root)
{
  if (!root) {
    return {};
  }

  queue<TreeNode*> que;
  que.push(root);
  vector<vector<int>> result;
  TreeNode *curr;
  while (!que.empty()) {
    size_t len = que.size();
    vector<int> curr_lvl;
    while (len--) {
      curr = que.front();
      que.pop();
      curr_lvl.push_back(curr->val);
      if (curr->left) {
        que.push(curr->left);
      }
      if (curr->right) {
        que.push(curr->right);
      }
    }
    result.push_back(curr_lvl);
  }

  return result;
}