#include <iostream>
#include <vector>

using namespace std;

int cache[100][100];
int n=5;
vector<vector<int>> grid = {
    {6},
    {1, 2},
    {3, 7, 4},
    {9, 4, 1, 7},
    {2, 7, 5, 9, 4}
};

int path2(int y, int x)
{
    // base case
    if(y == n-1) return grid[y][x];

    int& ret = cache[y][x];
    if(ret != -1) return ret;
    
    return ret = max(path2(y+1, x), path2(y+1, x+1)) + grid[y][x];
}

int countCache[100][100];
int count(int y, int x)
{
    if(y==n-1) return 1;

    int& ret = countCache[y][x];
    if(ret != -1) return ret;
    ret =0;

    if(path2(y+1, x+1) >= path2(y+1, x)) ret += count(y+1, x+1);
    if(path2(y+1, x+1) >= path2(y+1, x)) ret += count(y+1, x);

    return ret;

}
int main()
{
    memset(cache, -1, sizeof(cache));
    memset(countCache, -1, sizeof(countCache));
    // cout << "ret: " << path2(0,0);
    cout << "ret: " << count(0,0);
    return 0;
}