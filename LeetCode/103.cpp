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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // It must solve with BFS
        vector<vector<int>> ret;
        if(!root) return ret;
        
        int flag = 1; // odd:left even:right
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            vector<int> cur;
            int size = q.size();
            cout << size << endl;
            for(int i=0; i<size; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                cur.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(flag%2==0)
                reverse(cur.begin(), cur.end());

            ret.push_back(cur);
            flag++;
        }

        return ret;
    }
};

