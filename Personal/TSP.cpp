#include <iostream>
#include <vector>

using namespace std;

const int MAX = 20;
int n = 10; // number of cities
double dist[MAX][MAX]; // distance of two cities.
double INF = 987654321;
// path: the path made till now
// visited: visit or not
// currentLength: the length made till now
double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength)
{
    // base case
    if (path.size() == n )
        return currentLength + dist[path[0]][path.back()];
    double ret = INF;
    
    for(int next=0; next<n; next++)
    {
        if(visited[next]) continue;
        int here = path.back();
        path.push_back(next);
        visited[next] = true;

        double cand = shortestPath(path, visited, currentLength+dist[here][next]);
        ret = min(ret, cand);
        visited[next] = false;
        path.pop_back();
    }
    return ret;
}