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
    string retL="", retR="";
    string checkLeft(TreeNode* root)
    {
        if(!root)
            return "X";
            
        retL += checkLeft(root->left);
        retL += checkLeft(root->right);

        return to_string(root->val);
    }
    string checkRight(TreeNode* root)
    {
        if(!root)
            return "X";

        retR += checkRight(root->right);
        retR += checkRight(root->left);

        return to_string(root->val);
    }
    bool isSymmetric(TreeNode* root) {
        if(root->left)
            retL = root->left->val;
        if(root->right)
            retR = root->right->val;
        
        checkLeft(root->left);
        checkRight(root->right);
        
        return retL == retR;
    }
};
