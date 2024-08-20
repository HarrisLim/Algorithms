#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// adjacency list of graph
vector<vector<int>> adj;
// discover BFS to graph starts at 'start'  and return each vertices's visited order
vector<int> bfs(int start)
{
    // check out visiting to each vertex
    vector<bool> discovered(adj.size(), false);
    // queue keep the vertex list to visit
    queue<int> q;

    // visit order of vertex
    vector<int> order;
    discovered[start] = true;
    q.push(start);
    while(!q.empty())
    {
        int here = q.front();
        q.pop();
        // visit here
        order.push_back(here);
        // search every adjacent vertex
        for(int i=0; i<adj[here].size(); i++)
        {
            int there = adj[here][i];
            // insert to discovery list if it's first vertex, 
            if(!discovered[there])
            {
                q.push(there);
                discovered[there] = true;
            }
        }
    }
    return order;
}

int main()
{
    return 0;
}