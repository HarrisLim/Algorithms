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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder)
    {
        if(inorder.empty())
            return nullptr;

        int val = preorder.front();
        preorder.erase(preorder.begin());
        int idx = find(inorder.begin(), inorder.end(), val) - inorder.begin();

        TreeNode* root = new TreeNode(val);
        vector<int> left(inorder.begin(), inorder.begin() + idx);
        vector<int> right(inorder.begin()+ idx + 1, inorder.end());

        root->left = build(preorder, left);
        root->right = build(preorder, right);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        return build(preorder, inorder);
    }
};
