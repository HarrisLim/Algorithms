/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ret)
    {
        if(!root)
            return ;

        inorder(root->left, ret);
        ret.push_back(root->val);
        inorder(root->right, ret);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        inorder(root, ret);

        return ret;
    }
};

/*
// inorder: left -> root -> right
void inorder(node, arr)
{
    if(!node) return;

    inorder(node->left, arr);
    arr.push_back(node->val);
    inorder(node->right, arr);
}

// preorder: root -> left -> right
void preorder(node, arr)
{
    if(!node) return;

    arr.push_back(node->val);
    preorder(node->left, arr);
    preorder(node->right, arr);
}

// postorder: left -> right -> root
void postorder(node, arr)
{
    if(!node) return;

    postorder(node->left, arr);
    postorder(node->right, arr);
    arr.push_back(node->val);
}
*/
