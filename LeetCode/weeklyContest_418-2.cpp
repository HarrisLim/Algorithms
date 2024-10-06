class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        int m = invocations.size();
        set<int> st;
        vector<int> adj[n];
        for(auto vec : invocations)
        {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
        }

        queue<int> q;
        q.push(k);
        st.insert(k);
        vector<int> visited(n, 0);
        visited[k] = 1;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(int i: adj[node])
            {
                if(visited[i] == 0)
                {
                    st.insert(i);
                    q.push(i);
                    visited[i] =1;
                }
            }
        }

        bool flag = false;

        for(int i=0; i<m; i++)
        {
            int y=invocations[i][0];
            int x=invocations[i][1];

            if(st.find(y) == st.end() && st.find(x) != st.end())
                flag = true;
        }

        vector<int> ret;
        for(int i=0; i<n; i++)
        {
            if(flag)
                ret.push_back(i);
            else
                if(st.find(i) == st.end())
                    ret.push_back(i);
        }

        return ret;
    }
};

