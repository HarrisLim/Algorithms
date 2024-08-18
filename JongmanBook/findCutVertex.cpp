#include <iostream>
#include <vector>

using namespace std;

// adjacency list of graph
vector<vector<int>> adj;
// the order of discovered each. initialize to -1
vector<int> discovered;
// store if the point is a cut vertex.
vector<bool> isCutVertex;
int counter = 0;

// find the cut vertex rooted with here of subtree
// the return value is the discovery time of the earliest discovered vertex that can be reached
// via a back edge in the subtree.
// set 'isRoot = true' for the initial call.
int findCutVertex(int here, bool isRoot)
{
    // record discovery order
    discovered[here] = counter++;
    int ret = discovered[here];
    // count the number of descendant subtrees for vertex decision if root
    int children=0;
    for(int i=0; i<adj[here].size(); i++)
    {
        int there = adj[here][i];
        if(discovered[there] == -1)
        {
            children++;
            // the greatest number that can be go from this subtree
            int subtree = findCutVertex(there, false);
            // if the node is less than own, current point is cur vertex
            if(!isRoot && subtree >= discovered[here])
                isCutVertex[here] = true;
            ret = min(ret, subtree);
        }
        else
            ret = min(ret, discovered[there]);
    }
    // if root, cut vertex is determined by the number of subtree
    if(isRoot) isCutVertex[here] = (children >= 2);
    return ret;
}

int main()
{

    return 0;
}