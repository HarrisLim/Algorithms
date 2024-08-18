#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// the adjacency list of graph
vector<vector<int>> adj;
// component starts with number 0
// vertices belonging to the same strongly connected componenet share the same component number.
vector<int> sccId;
// the discovery order of each vertex
vector<int> discovered;
// stack that stores the number of vertex
stack<int> st;
int sccCounter, vertexCounter;
// return minimun discovery order of vertices 
// that can go through back edge or cross edge in the subtree rooted with here
// (ignore if already cross edge is connected with vertex that tied scc )
int scc(int here)
{
    int ret = discovered[here] = vertexCounter++;
    // put here in stack. here's descendants get into stack before here
    st.push(here);
    for(int i=0; i<adj[here].size(); i++)
    {
        int there = adj[here][i];
        // (here, there) is tree edge
        if(discovered[there] == -1)
            ret = min(ret, scc(there));
        // if it's not cross edge that should ignore
        else if(sccId[there] == -1)
            ret = min(ret, discovered[there]);
    }

    // check if cut the vertex at here
    if(ret == discovered[here])
    {
        // tie the ramaining vertexs in the subtree rooted with here with a component
        while(true)
        {
            int t = st.top();
            st.pop();
            sccId[t] = sccCounter;
            if(t == here) break;
        }
        sccCounter++;
    }
    return ret;
}
// scc algorithm by tarjan
vector<int> tarjanSCC()
{
    // initialize every arrays
    sccId = discovered = vector<int>(adj.size(), -1);
    // initialize counter
    sccCounter = vertexCounter = 0;
    // call scc about every vertices
    for(int i=0; i<adj.size(); i++)
        if(discovered[i] == -1)
            scc(i);
            
    return sccId;
}

int main()
{

    return 0;
}