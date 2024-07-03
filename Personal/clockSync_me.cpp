#include <iostream>
#include <vector>

using namespace std;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;
const char linked[SWITCHES][CLOCKS+1] = {
    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......xxx.x.x...",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x.."};

bool areAligned(vector<int>& clocks)
{
    bool ret=false;
    for(int i=0; i<clocks.size(); i++)
    {
        if(clocks.at(i) == 12) ret = true;
        else ret = false;
    }   
    return ret;
}

void push(vector<int>& clocks, int swtch)
{
    for(int clock=0; clock < CLOCKS; clock++)
    {
        if(linked[swtch][clock] == 'x')
        {
            clocks[clock] += 3;
            if(clocks[clock] == 15) clocks[clock] = 3;
        }
    }
}

int solve(vector<int>& clocks, int swtch)
{
    if(swtch == SWITCHES) return areAligned(clocks) ? 0 : INF;

    int ret = INF;
    for(int cnt=0; cnt<4; cnt++)
    {
        ret = min(ret, cnt+solve(clocks, swtch+1));
        push(clocks, swtch);
    }
    return ret;
}
int main()
{
    // vector<int> clocks = {12, 6, 6, 6, 6, 6, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12};
    vector<int> clocks = {12, 9, 3, 12, 6, 6, 9, 3, 12, 9, 12, 9, 12, 12, 6, 6};
    int ret =0;
    ret = solve(clocks, 0);
    
    cout << "ret: "<< ret << endl;

    return 0;
}