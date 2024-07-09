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
int ret=0;

void toEndPoint(int y, int x, int step)
{
    // debugging for checking
    int grid_display[7][7] =
    {
        {2, 5, 1, 6, 1, 4, 1},
        {6, 1, 1, 2, 2, 9, 3},
        {7, 2, 3, 2, 1, 3, 1},
        {1, 1, 3, 1, 7, 1, 2},
        {4, 1, 2, 3, 4, 1, 2},
        {3, 3, 1, 2, 3, 4, 1},
        {1, 5, 2, 9, 4, 7, 0}
    };
    // base case
    if(y < 0 || y > 6 || x < 0 || x > 6) return;
    grid_display[y][x] = 0;
    for(int i=0; i<7; i++)
    {
        for(int j=0; j<7; j++) 
            cout << grid_display[i][j] << ' ';
        cout << "\n";
    }
    cout << "ENDENDENDENDEND y: " << y  << ", x: " << x << '\n';
    
    if(y==6 && x==6) 
    {
        ret=1;
        return;
    }

    toEndPoint(y+step, x, grid[y+step][x]);
    toEndPoint(y, x+step, grid[y][x+step]);

    return ;
}

int main()
{
    toEndPoint(0, 0, 2);
    cout << "ret: " << ret << endl;
    return 0;
}