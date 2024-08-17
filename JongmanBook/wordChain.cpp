#include <iostream>
#include <vector>

using namespace std;

// adjacency matrix of graph
vector<vector<int>> adj;
// the list of words starts with i and ends with j
vector<string> graph[26][26];
// indegree: the number of words starts with i
// outdegree: the number of words ends with i
vector<int> indegree, outdegree;

void allPrint()
{
    for(int i=0; i<26; i++)
        for(int j=0; j<26; j++)
            for(auto x: graph[i][j])
                cout << "graph["<<i<<"]["<<j<<"]:"<< x << " ";

    cout << endl;

    char c = 'a';
    cout << "   a b c d e f g h i j k l m n o p q r s t u v w x y z"<< endl;
    for(int i=0; i<26; i++)
    {   
        cout << c++ << ": ";
        for(int j=0; j<26; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    cout << "   a b c d e f g h i j k l m n o p q r s t u v w x y z"<< endl;
}
void makeGraph(const vector<string>& words)
{
    // initialize a global variable
    for(int i=0; i<26; i++)
        for(int j=0; j<26; j++)
            graph[i][j].clear();
    
    adj = vector<vector<int>>(26, vector<int>(26, 0));
    indegree = outdegree = vector<int>(26, 0);

    // add each words to graph
    for(int i=0; i<words.size(); i++)
    {
        int a = words[i][0] - 'a';
        int b = words[i][words[i].size()-1] - 'a';
        graph[a][b].push_back(words[i]);
        adj[a][b]++;
        outdegree[a]++;
        indegree[b]++;
    }
    allPrint();
}

// when you get the directed graph of adjacency matrix, calculate Euler circuit or trail
void getEulerCircuit(int here, vector<int>& circuit)
{
    for(int there=0; there<adj.size(); there++)
    {
        while(adj[here][there] > 0)
        {
            // remove the edge so that void dup
            adj[here][there]--;
            getEulerCircuit(there, circuit);
        }
    }
    circuit.push_back(here);
}

// return Euler circuit or trail of current graph
vector<int> getEulerTrailOrCircuit()
{
    vector<int> circuit;
    
    // at first, find trail if that has a start point
    for(int i=0; i<26; i++)
    {
        if(outdegree[i] == indegree[i]+1)
        {
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }

    // if it's circuit, starts with any node adjacent edge
    for(int i=0; i<26; i++)
    {
        if(outdegree[i])
        {
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }

    // if faluts, return empty array
    return circuit;
}

// check the presence of Euler circuit/trail in the current graph
bool checkEuler()
{
    // teporary the number of start and end point
    int plus1=0, minus1=0;
    for(int i=0; i<26; i++)
    {
        int delta = outdegree[i] - indegree[i];
        // every degree of node should be -1, 1 or 0
        if(delta < -1 || 1 < delta) return false;
        if(delta == 1) plus1++;
        if(delta == -1) minus1++;
    }
    // start point and end point should have one or zero each
    return (plus1 == 1 && minus1 == 1) || (plus1 == 0 && minus1 == 0);
}

string solve(const vector<string>& words)
{
    makeGraph(words);
    // if not match degree, return IMPOSSIBLE
    if(!checkEuler()) return "IMPOSSIBLE";
    // find Euler circuit or trail
    vector<int> circuit = getEulerTrailOrCircuit();
    // if couldnt visited every edges, return "IMPOSSIBLE";
    if(circuit.size() != words.size() +1) return "IMPOSSIBLE";

    // reverse the visited order and make a words and return
    reverse(circuit.begin(), circuit.end());
    for(auto q:circuit)
        cout << " C: "<< q << " ";
    cout <<endl;
    string ret;
    for(int i=1; i<circuit.size(); i++)
    {
        int a = circuit[i-1], b = circuit[i];
        if(ret.size()) ret += " ";
        ret += graph[a][b].back();
        graph[a][b].pop_back();
    }
    return ret;
}

int main()
{
    vector<string> str = {"dog", "god", "dragon", "need"};
    // vector<string> str = {"ab", "cd"};
    cout << "\n";
    cout << solve(str);
    return 0;
}