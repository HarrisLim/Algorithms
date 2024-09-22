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
// ## BFS Approach
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(!root) 
            return v;

        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<int> cur;

            for(int i=0; i<size; i++)
            {
                TreeNode* subTree = q.front();
                q.pop();

                cur.push_back(subTree->val);

                if(subTree->left) q.push(subTree->left);
                if(subTree->right) q.push(subTree->right);
            }
            v.push_back(cur);
        }

        return v;    
    }
};
/*
// ## DFS Approach
class Solution {
public:
    vector<vector<int>> v;
    int findNode(TreeNode* root, int depth)
    {
        if(!root)
            return INT_MIN;

        if (v.size() < depth) 
            v.push_back(vector<int>());

        int l = findNode(root->left, depth+1);
        if(l != INT_MIN)
            v[depth].push_back(l);

        int r = findNode(root->right, depth+1);
        if(r != INT_MIN)
            v[depth].push_back(r);

        return root->val;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root)
            v.push_back({root->val});

        findNode(root, 1);

        return v;    
    }
};
*/
