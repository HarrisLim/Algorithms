#include <iostream>
#include <vector>

using namespace std;

string alphbet = "abcdefghijklmnopqrstuvwxyz";
// make a adjacency list
vector<vector<int>> adj;

void makeGraph(const vector<string>& words)
{
    // 26 x 26
    adj = vector<vector<int>>(26, vector<int>(26, 0));
    for(int j=1; j<words.size(); j++)
    {
        int i=j-1, len = min(words[i].size(), words[j].size());
        // find the reason why word[i] is located before word[j]
        for(int k=0; k<len; k++)
        {
            if(words[i][k] != words[j][k])
            {
                // the reason why use "-a" is that get the index of alphabet
                // for example) 'a'-'a'=0, 'b'-'a'=1, 'c'-'a'=1
                int a = words[i][k] - 'a';
                int b = words[j][k] - 'a';
                adj[a][b] = 1;
                break;
            }
        }
    }
}

vector<int> seen, order;
void dfs(int here)
{
    seen[here] = 1;
    for(int there=0; there<adj.size(); there++)
        if(adj[here][there] && !seen[there])
            dfs(there);

    order.push_back(here);
}
// return the reuslt after topological sorting
// if the graph is not DAG, return empty vector
vector<int> topologicalSort()
{
    int m = adj.size();
    seen = vector<int>(m,0);
    order.clear();
    for(int i=0; i<m; i++)
        if(!seen[i]) 
            dfs(i);
    reverse(order.begin(), order.end());

    // if the graph isnt DAG, there would be reverse line in the result of sorting
    for(int i=0; i<m; i++)
        for(int j=i+1; j<m; j++)
            if(adj[order[j]][order[i]])
                return vector<int>();

    // if empty, return the result from DFS
    return order;
}

int main()
{
    vector<string> list = {
        {"gg"},
        {"kia"},
        {"lotte"},
        {"lg"},
        {"hanhwa"}
    };
    makeGraph(list);
    // for(auto x: adj)
    // {
    //     for(int i=0; i<x.size(); i++)
    //         cout << x[i] << " ";
    //     cout << endl;
    // }
    topologicalSort();
    for(auto x: order)
        cout << x << " ";

    return 0;
}