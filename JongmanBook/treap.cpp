#include <iostream>

using namespace std;

typedef int KeyType;
// store a node of treap(tree+heap)
struct Node
{
    // elements that stored at node
    KeyType key;
    // the priority of this node(priority)
    // the size of subtree that rooted at this node(size)
    int priority, size;
    // pointers of two children
    Node *left, *right;
    // create priority of random numbers and initiate size, left and right.
    Node(const KeyType& _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL){}
    
    void setLeft(Node* newLeft)
    {
        left = newLeft;
        calcsize();
    }
    void setRight(Node* newRight)
    {
        right = newRight;
        calcsize();
    }

    // update size
    void calcsize() 
    {
        size =1;
        if(left) size += left->size;
        if(right) size += right->size;
    }
};

typedef pair<Node*, Node*> NodePair;
// split the treap with root as the root into two treaps:
// one with values less than the key and
// one with values greater than or equal to the key
NodePair split(Node* root, KeyType key)
{
    if(root == NULL) return NodePair(NULL, NULL);
    // if root is less than key, split right subtree.
    if(root->key < key)
    {
        NodePair rs = split(root->right, key);
        root->setRight(rs.first);
        return NodePair(root, rs.second);
    }
    // if root is greater than or equal to the key, split left subtree.
    NodePair ls = split(root->left, key);
    root->setLeft(ls.second);
    return NodePair(ls.first, root);
}

// return the root of result treap after new node insert into the treap with root as the root
Node* insert(Node* root, Node* node)
{
    if(root == NULL) return node;
    // node need to replace root. the subtree split and make descendants respectively
    if(root->priority < node->priority)
    {
        NodePair splitted = split(root, node->key);
        node->setLeft(splitted.first);
        node->setRight(splitted.second);
        return node;
    }
    else if(node->key < root->key)
        root->setLeft(insert(root->left, node));
    else
        root->setRight(insert(root->right, node));
    return root;
}

// root = insert(root, new Node(value));

// a and b are two treap and when max(a) < min(b), a and b should merge.
Node* merge(Node* a, Node* b)
{
    if(a == NULL) return b;
    if(b == NULL) return a;
    if(a->priority < b->priority)
    {
        b->setLeft(merge(a, b->left));
        return b;
    }
    a->setRight(merge(a->right, b));
    return a;
}

// erase key of treap with root as the root and return the root of result treap
Node* erase(Node* root, KeyType key)
{
    if(root == NULL)
        return root;
    // erase root and return both subtree after merge
    if(root->key == key)
    {
        Node* ret = merge(root->left, root->right);
        delete root;
        return ret;
    }
    if(key < root->key)
        root->setLeft(erase(root->left, key));
    else
        root->setRight(erase(root->right, key));
    return root;
}

// return k-th element among tree with root as the root
Node* kth(Node* root, int k)
{
    // calculate the size of left subtree first
    int leftSize = 0;
    if(root->left != NULL) leftSize = root->left->size;
    if(k <= leftSize) return kth(root->left, k);
    if(k == leftSize +1) return root;
    return kth(root->right, k-leftSize-1);
}

// return the values less than key
int countLessThan(Node* root, KeyType key)
{
    if(root == NULL) return 0;
    if(root->key >= key)
        return countLessThan(root->left, key);
    int ls = (root->left ? root->left->size : 0);
    return ls + 1 + countLessThan(root->right, key);
}