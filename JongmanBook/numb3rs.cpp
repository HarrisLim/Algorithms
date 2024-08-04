#include <iostream>
#include <vector>

using namespace std;

/*
    n: the number of towns
    d: days
    p: the point of jail
    q: a town that need to calculate 
*/
int n=5, d=2, p=0, q=3;
// connected[i][j]: check connection status
// deg[i]: the number of town connected town i
int connected[51][51] = 
{
    {0, 1, 1, 1, 0},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0},
    {1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0}
};
int deg[51] = {0, 2, 4};
double search(vector<int>& path)
{
    // base case
    if(path.size() == d+1)
    {
        // invalidity, if it ends at q
        if(path.back() != q) return 0.0;
        // calculate the probability that path comes out 
        double ret = 1.0;
        for(int i=0; i+1 < path.size(); i++)
            ret /= deg[path[i]];
        return ret;
    }
    double ret = 0;
    // decide  next path position
    for(int there =0; there<n; there++)
    {
        if(connected[path.back()][there])
        {
            path.push_back(there);
            ret += search(path);
            path.pop_back();
        }
    }
    
    return ret;
}
double cache[51][101];
double search3(int here, int days)
{
    // base case
    if(days == 0) return (here == p ? 1.0 : 0.0);
    // memoization
    double& ret = cache[here][days];
    if(ret > 0.5) return ret;
    ret = 0.0;

    for(int there=0; there<n; there++)
        if(connected[here][there])
            ret += search3(there, days-1) / deg[there];
    
    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));
    vector<int> path = {0,1,2,3,4};

    // cout << "ret_1: " << search(path) << endl;
    cout << "ret_2: " << search3(0, d) << endl;

    return 0;
}