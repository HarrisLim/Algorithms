#include <iostream>
#include <vector>

using namespace std;

// adjacency list of graph
vector<vector<int>> adj;
// discovered[i] = the discovered order of ith point
// finished[i] = if dfs(i) is finished, 1 otherwise 0
vector<int> discovered, finished;
// the number of discovered node so far
int counter;

void dfs2(int here)
{
    discovered[here] = counter++;

    for(int i=0; i<adj[here].size(); i++)
    {
        int there = adj[here][i];
        cout << "(" << here << "," << there << ") is a";

        // if not visited, visit
        if(discovered[there] == -1)
        {
            cout << "tree edge" << endl;
            dfs2(there);
        }
        // if there is discovered later than here, there would be here's descendant
        else if(discovered[here] < discovered[there])
            cout << "forward edge" << endl;
        // if dfs2(there) is not finished yet, there would be here's ancestor
        else if(finished[there] == 0)
            cout << "back edge" << endl;
        // all other cases are cross edge
        else 
            cout << "cross edge" << endl;
    }
    finished[here] =1;
}

int main()
{
    return 0;
}