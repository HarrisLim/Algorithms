#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
// start at 'start' first, bfs to graph and
// calculate bfs spanning tree and the shortest path from start point to end point.
// the shortest path from 'distance[i]=start' to 'i'
// parent[i] = the number of parents of 'i' in bfs spanning tree. if it's root, it would be own number of root
void bfs2(int start, vector<int>& distance, vector<int>& parent)
{
    distance = vector<int>(adj.size(), -1);
    parent = vector<int>(adj.size(), -1);

    // queue that keeps vertices list to visit
    queue<int> q;
    distance[start] = 0;
    parent[start] = start;
    q.push(start);
    while(!q.empty())
    {
        int here = q.front();
        q.pop();
        // check every adjacent vertex of 'here'
        for(int i=0; i<adj[here].size(); i++)
        {
            int there = adj[here][i];
            // if the vertex is seen for the first time, add it to the visted list
            if(distance[there] == -1)
            {
                q.push(there);
                distance[there] = distance[here]+1;
                parent[there] = here;
            }
        }
    }
}

// calculate the shortest path from 'v' to start point
vector<int> shortestpath(int v, const vector<int>& parent)
{
    vector<int> path(1, v);
    while(parent[v] != v)
    {
        v = parent[v];
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}