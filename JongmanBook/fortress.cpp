#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    vector<TreeNode*> children;
};

// stores the length of the longest leaf to leaf path found so far.
int longest;
// return the height of the subtree rooted at 'root'
int height(TreeNode* root)
{
    // calculate the height of the subtree rooted at each children
    vector<int> heights;
    for(int i=0; i<root->children.size(); i++)
        heights.push_back(height(root->children[i]));
    
    if(heights.empty()) return 0;
    sort(heights.begin(), heights.end());
    // consider if root is the heighest root
    if(heights.size() >= 2)
        longest = max(longest, 2 + heights[heights.size()-2] + heights[heights.size()-1]);
    
    // tree height is calculated as the maximum value of its subtree's height plus 1
    return heights.back() + 1;
}

// calculate the longest path between each nodes
int solve(TreeNode* root)
{
    longest =0;
    // choose the greater value between the tree's height and max leaf to leaf path
    int h = height(root);
    return max(longest, h);
}

// make a tree rooted wall at 'root'
TreeNode* getTree(int root)
{
    TreeNode* ret = new TreeNode();
    for(int ch=0; ch<n; ch++)
        // if ch wall is related root wall directly, make a tree and add descendant list
        if(isChild(root, ch))
            ret->children.push_back(getTree(ch));
    
    return ret;
}

// input data
int n, y[100], x[100], radius[100];
// return x^2
int sqr(int x)
{
    return x*x;
}
// return square of distance of between A and B
int sqrdist(int a, int b)
{
    return sqr(y[a] - y[b]) + sqr(x[a] - x[b]);
}
// check if A wall include B wall
bool encloses(int a, int b)
{
    return radius[a] > radius[b] &&
        sqrdist(a,b) < sqr(radius[a] - radius[b]);
}
// check if parent is child's parent in wall tree
bool isChild(int parent, int child)
{
    if(!encloses(parent, child)) return false;
    for(int i=0; i<n; i++)
        if(i != parent && i != child && encloses(parent, i) && encloses(i, child))
            return false;
    return true;
}
