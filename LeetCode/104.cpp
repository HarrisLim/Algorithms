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
    int com=-1;
    int solve(TreeNode* root, int l, int r, int depth)
    {
        if(!root) return depth+1;

        solve(root->left, l+1, r, depth+1);
        solve(root->right, l, r+1, depth+1);

        return com = max(com, depth);
    }

    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        
        return solve(root, 0, 0, 1);
    }
};
