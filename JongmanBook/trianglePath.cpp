#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> grid = {
    {6},
    {1, 2},
    {3, 7, 4},
    {9, 4, 1, 7},
    {2, 7, 5, 9, 4}
};
// int maxValue=0;

int gridSum(int y, int x, int sum)
{
    // base case
    if(y>4 || x>grid[y].size()) return 0;
    if(y==4) return sum+grid[y][x];
    int ret=0;

    sum += grid[y][x];
    // cout << "sum: " << sum << " ";
    ret = max(gridSum(y+1,x, sum), gridSum(y+1,x+1, sum));
    return ret;
}

// using memoization
int cache[100][100];
int gridSum2(int y, int x)
{
    if(y == 4) return grid[y][x];
    //memoization
    int& ret = cache[y][x];
    return ret = max(gridSum2(y+1,x), gridSum2(y+1,x+1)) + grid[y][x];
}

int main()
{
    memset(cache, -1, sizeof(cache));
    cout << "ret_1: " << gridSum(0,0,0) << endl;
    cout << "ret_2: " << gridSum2(0,0);
}