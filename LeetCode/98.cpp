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
    // bool check(TreeNode* root, bool ret, int node)
    bool check(TreeNode* root, long low, long high)
    {
        if(!root)
            return true;

        if(root->val <= low || root->val >= high)
            return false;

        bool left = check(root->left, low, root->val);
        bool right = check(root->right, root->val, high);

        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        
        bool ret=true;

        return check(root, LONG_MIN, LONG_MAX);
    }
};

