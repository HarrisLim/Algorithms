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
    TreeNode* convert(int left, int right, vector<int>& arr)
    {
        if(left > right)
            return nullptr;
        
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = convert(left, mid-1, arr);
        root->right = convert(mid+1, right, arr);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {

        return convert(0, nums.size()-1, nums);
    }
};
