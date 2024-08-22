#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

const int MAX_DISCS = 12;
int getA(int state, int index)
{
    return (state >> (index * 2)) & 3;
}
int setA(int state, int index, int value)
{
    return (state & ~(3 << (index * 2))) | (value << (index * 2));
}
int c[1<<(MAX_DISCS*2)];

int bfs(int discs, int begin, int end)
{
    if(begin == end) return 0;
    queue<int> q;
    memset(c, -1, sizeof(c));
    q.push(begin);
    c[begin] = 0;
    while(!q.empty())
    {
        int here = q.front();
        q.pop();

        int top[4] = {-1, -1, -1, -1};
        for(int i=discs-1; i>=0; i--)
            top[getA(here, i)] = i;
        
        for(int i =0; i<4; i++)
        {
            if(top[i] != -1)
            {
                for(int j=0; j<4; j++)
                {
                    if(i != j && (top[j] == -1 || top[j] > top[i]))
                    {
                        int there = setA(here, top[i], j);
                        if(c[there] != -1) continue;
                        c[there] = c[here] + 1;
                        if(there == end) return c[there];
                        q.push(there);
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
    cout << bfs(5, 1, 5);
    return 0;
}