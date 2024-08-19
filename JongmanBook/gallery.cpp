#include <iostream>
#include <vector>

using namespace std;

int V;
vector<int> adj[1000];
vector<bool> visited;
const int UNWATCHED = 0;
const int WATCHED = 1;
const int INSTALLED = 2;
// the number of installed camera
int installed;
// return here's info
int dfs(int here)
{
    visited[here] = true;
    int children[3] = {0, 0, 0};
    for(int i=0; i<adj[here].size(); i++)
    {
        int there = adj[here][i];
        if(!visited[there])
            children[dfs(there)]++;
    }
    
    if(children[UNWATCHED])
    {
        installed++;
        return INSTALLED;
    }

    if(children[INSTALLED])
        return WATCHED;

    return UNWATCHED;
}

int installCamera()
{
    installed = 0;
    visited = vector<bool>(V, false);
    for(int u = 0; u < V; u++)
        if(!visited[u] && dfs(u) == UNWATCHED)
            installed++;
    
    return installed;
}

int main()
{
    vector<vector<int>> info = {
                        {0, 1},
                        {1, 2},
                        {1, 3},
                        {2, 5},
                        {0, 4}
                        };
    
    return 0;
}
