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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder)
    {
        if(inorder.empty())
            return nullptr;

        int val = postorder.back();
        postorder.pop_back();

        int idx = find(inorder.begin(), inorder.end(), val) - inorder.begin();

        TreeNode* node = new TreeNode(val);
        vector<int> right(inorder.begin()+ idx + 1, inorder.end());
        vector<int> left(inorder.begin(), inorder.begin()+idx);
        
        node->right = build(right, postorder);
        node->left = build(left, postorder);

        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder);
    }
};
