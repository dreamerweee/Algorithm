/*
* 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
*百度百科中最近公共祖先的定义为：
	“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
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
class Solution {
public:
    bool FindNode(TreeNode *node, TreeNode *p, TreeNode *q) {
        if (!node) {
        	return false;
        }
        int left = FindNode(node->left, p, q) ? 1 : 0;
        int right = FindNode(node->right, p, q) ? 1 : 0;
        int mid = (node == p || node == q) ? 1 : 0;

        if (mid + left + right >= 2) {
        	m_node = node;
        }
        return (mid + left + right) > 0;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        FindNode(root, p, q);
        return m_node;
    }
private:
    TreeNode *m_node = nullptr;
};