#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int _val, struct TreeNode *_l = nullptr, struct TreeNode *_r = nullptr) :
        val(_val), left(_l), right(_r)
    { }
};

TreeNode* CreateTree()
{
    int val;
    cin >> val;
    if (val == -11)  // 使用-11来结束该子树分支的创建
        return nullptr;
    TreeNode *root = new TreeNode(val);
    root->left = CreateTree();
    root->right = CreateTree();

    return root;
}

void PrintTreePrevRecursion(TreeNode *root)
{
    if (!root) {
        return ;
    }
    cout << root->val << " ";
    PrintTreePrevRecursion(root->left);
    PrintTreePrevRecursion(root->right);
}

// 非递归前序遍历
void PrintTreePrev(TreeNode *root)
{
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode *node = st.top();
        st.pop();
        cout << node->val << " ";
        if (node->right) {
            st.push(node->right);
        }
        if (node->left) {
            st.push(node->left);
        }
    }
    cout << endl;
}

void PrintTreeInterRecursion(TreeNode *root)
{
    if (!root) {
        return ;
    }
    PrintTreeInterRecursion(root->left);
    cout << root->val << " ";
    PrintTreeInterRecursion(root->right);
}

// 非递归中序遍历
void PrintTreeInter(TreeNode *root)
{
    stack<TreeNode*> st;
    TreeNode *p = root;
    while (p || !st.empty()) {
        while (p) {
            st.push(p);
            p = p->left;
        }
        if (!st.empty()) {
            p = st.top();
            st.pop();
            cout << p->val << " ";
            p = p->right;
        }
    }
    cout << endl;
}

void PrintTreeBackRecursion(TreeNode *root)
{
    if (!root) {
        return ;
    }
    PrintTreeBackRecursion(root->left);
    PrintTreeBackRecursion(root->right);
    cout << root->val << " ";
}

// 非递归后序遍历
void PrintTreeBack(TreeNode *root)
{
    stack<TreeNode*> st;
    TreeNode *cur = root;
    TreeNode *prev = nullptr;
    while (cur || !st.empty()) {
        while (cur) {
            st.push(cur);
            cur = cur->left;
        }
        if (!st.empty()) {
            cur = st.top();
            if (cur->right && cur->right != prev) {
                cur = cur->right;
            } else {
                cout << cur->val << " ";
                prev = cur;
                cur = nullptr;
                st.pop();
            }
        }
    }
    
    cout << endl;
}

int main(void)
{
    TreeNode *root = CreateTree();

    cout << "prev recur  : ";
    PrintTreePrevRecursion(root);
    cout << endl;

    cout << "prev nrecur : ";
    PrintTreePrev(root);

    cout << "inter recur : ";
    PrintTreeInterRecursion(root);
    cout << endl;

    cout << "inter nrecur: ";
    PrintTreeInter(root);

    cout << "back recur  : ";
    PrintTreeBackRecursion(root);
    cout << endl;

    cout << "back nrecur : ";
    PrintTreeBack(root);
    
    return 0;
}