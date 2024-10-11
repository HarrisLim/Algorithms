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
    TreeNode* build(vector<int>& preorder, vector<int>& postorder)
    {
        if(preorder.empty()|| postorder.empty())
            return nullptr;
        
        int val = preorder.front();
        preorder.erase(preorder.begin());

        TreeNode* node = new TreeNode(val);
        if (postorder.size() == 1) {
            postorder.pop_back();
            return node;
        }

        int leftVal = preorder.front();
        int idx = find(postorder.begin(), postorder.end(), leftVal) - postorder.begin();
        
        vector<int> left(postorder.begin(), postorder.begin()+idx+1);
        vector<int> right(postorder.begin()+idx+1, postorder.end()-1);
        
        node->left = build(preorder, left);
        node->right = build(preorder, right);
        
        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        return build(preorder, postorder);
    }
};
