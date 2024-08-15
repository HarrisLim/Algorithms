#include <iostream>
#include <vector>

using namespace std;

// adjacency list of graph
vector<vector<int>> adj;
// check visit or not
vector<bool> visited;
// implement DFS
void dfs(int here)
{
    cout << "DFS visits " << here << endl;
    visited[here] = true;
    // circulate every adjacent node
    for(int i=0; i<adj[here].size(); i++)
    {
        int there = adj[here][i];
        // if unvisited, visit
        if(!visited[there])
            dfs(there);
    }
    // there is any node more, therefore return previous node
}

// visit every node
void dfsAll()
{
    // initiate as unvisited
    visited = vector<bool>(adj.size(), false);
    // if unvisted, visit as circulate every node
    for(int i=0; i<adj.size(); i++)
        if(!visited[i])
            dfs(i);
}

int main()
{

    return 0;
}