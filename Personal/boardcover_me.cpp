#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board = {
    {1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1},
    {1, 1, 0, 0, 1, 1, 1}
};
const int coverType[4][3][2] = {
    {{0,0}, {0,1}, {1,1}},
    {{0,0}, {1,0}, {1,1}},
    {{0,0}, {1,0}, {0,1}},
    {{0,0}, {1,0}, {1,-1}}
}; 

bool set(int y, int x, int type, vector<vector<int>>& board, int delta)
{
    bool ok = true;
    for (int i=0; i<3; i++)
    {
        int ny = y + coverType[type][i][0];
        int nx = x + coverType[type][i][1];

        // get out of board.. keep searching
        if(ny<0 || ny>=board.size() || nx<0 || nx>=board[0].size())
            ok = false;
        else if ((board[ny][nx] += delta) > 1)
            ok = false;
    }
    return ok;
}

int cover(vector<vector<int>>& board)
{
    int y=-1, x=-1;
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board[i].size(); j++)
        {
            if(board[i][j] == 0)
            {
                y=i;
                x=j;
                break;
            }
        }
        if(y != -1) break;
    }

    if(y==-1) return 1;
    int ret = 0;

    for(int type=0; type<4; type++)
    {
        if(set(y, x, type, board, 1))
            ret+=cover(board);
        set(y, x, type, board, -1);
    }
    return ret;
}

int main()
{
    int ret;
    
    ret = cover(board);
    cout << "ret: " << ret << endl;

    return 0;
}