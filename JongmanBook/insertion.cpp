#include <iostream>
#include <vector>

using namespace std;

int n, shifted[50000];
int A[50000];
// stroes at A[] according to n, shifted[]
void solve()
{
    // make a treap that can store the numbers between 1~N
    Node* candidates = NULL;
    for(int i=0; i<n; i++)
        candidates = insert(candidates, new Node(i+1));

    // fill A[] from back
    for(int i=n-1; i>=0; i--)
    {
        // there is larger-th larger than this number
        int larger = shilfted[i];
        Node* k = kth(candidates, i+1-larger);
        A[i] = k->key;
        candidates = erase(candidates, k->key);
    }
}

int main()
{
    return 0;
}