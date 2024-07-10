#include <iostream>

using namespace std;
// 0 is end point
const int grid[7][7] = 
{
    {2, 5, 1, 6, 1, 4, 1},
    {6, 1, 1, 2, 2, 9, 3},
    {7, 2, 3, 2, 1, 3, 1},
    {1, 1, 3, 1, 7, 1, 2},
    {4, 1, 2, 3, 4, 1, 2},
    {3, 3, 1, 2, 3, 4, 1},
    {1, 5, 2, 9, 4, 7, 0}
};
int checked[7][7];
// bruteforce
bool jump(int y, int x)
{
    // base case
    if(y >= 7 || x >= 7) return false;
    
    if(y==6 && x==6) 
    {
        return true;
    }
    int jumpSize = grid[y][x];
    return jump(y+jumpSize, x) || jump(y, x+jumpSize);
}
// using memoizatoin
int jump2(int y, int x)
{
    if(y>=7 || x>=7) return 0;
    if(y==6 && x ==6) return 1;
    
    // memoization
    int& ret = checked[y][x];
    if(ret != -1) return ret;
    int jumpSize = grid[y][x];
    return ret = jump(y+jumpSize, x) || jump(y, x+jumpSize);
}
int main()
{
    // -1:unchecked
    memset(checked, -1, sizeof(checked));

    cout << "ret_1: " << jump(0, 0) << endl;
    cout << "ret_2: " << jump2(0, 0) << endl;
    return 0;
}