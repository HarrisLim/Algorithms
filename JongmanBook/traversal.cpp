#include <iostream>
#include <vector>

using namespace std;

vector<int> slice(const vector<int>& v, int a, int b)
{
    vector<int> x (v.begin()+a, v.begin()+b);
    
    for(int a: x)
        cout << "a: " << a << ' ';
    return x;
    // return vector<int>(v.begin()+a, v.begin()+b);
}

void printPostOrder(const vector<int>& preorder, const vector<int>& inorder)
{
    // numbers of node
    const int N = preorder.size();
    // base case: if tree is empty, return
    if(preorder.empty()) return;
    
    const int root = preorder[0];
    // find the size of left sub tree by result of inorder 
    const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
    
    // find the size of right sub tree by N = Left sub tree - root
    const int R = N - 1 - L;
    // cout << "inorder.begin():" << *inorder.begin() << " N:" << N << " L:" << L << " R:" << R << endl;
    // find left side and right side
    printPostOrder(slice(preorder, 1, L+1), slice(inorder, 0, L));
    printPostOrder(slice(preorder, L+1, N), slice(inorder, L+1, N));

    cout << "root: " << root << ' ';
}

int main()
{
    vector<int> preorder = {27, 16, 9, 12, 54, 36, 72};
    vector<int> inorder = {9, 12, 16, 27, 36, 54, 72};

    printPostOrder(preorder, inorder);
    return 0;
}