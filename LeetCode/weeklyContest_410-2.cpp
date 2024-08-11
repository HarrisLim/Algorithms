/*Q2. Count the Number of Good Nodes*/
class Solution {
public:
    int DFS(int u, int prv, int& ans, vector<vector<int>>& adj)
    {
        int c=-1, S=0;
        bool f=1;
        for(auto& i : adj[u])
        {
            if(i==prv) continue;
            int sz = DFS(i, u, ans, adj);
            S += sz;
            if (c == -1) c = sz;
            else if (c != sz) f = 0;
        }
        ans += f;
        return S+1;
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size()+1);
        // make adjacency list
        for(auto& i: edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        // for(int i=0; i<adj.size(); i++)
            // for(int j=0; j<adj[i].size(); j++)
                // cout << "["<<i<<"]: "<<adj[i][j] << " ";

        int ans=0;
        DFS(0, -1, ans, adj);
        return ans;
    }
};