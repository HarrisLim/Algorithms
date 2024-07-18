#include <iostream>
#include <string>

using namespace std;

int INF=987654321;
string N = "11111222";

int classify(int start, int end)
{
    string M = N.substr(start, end-start);

    if(M == string(M.size(), M[0])) return 1;

    bool progressive = true;
    for(int i=1; i<M.size(); i++)
        if(M[i+1]-M[i] != M[1]-M[0])
            progressive = false;

    if(progressive && abs(M[1] - M[0])==1) return 2;

    int alternating = true;
    for(int i=0; i<M.size(); i++)
        if(M[i] != M[i%2])
            alternating = false;

    if(alternating) return 4;
    if(progressive) return 5;

    return 10;
}

int cache[10002];
int solve(int begin)
{
    if(begin == N.size()) return 0;
    int& ret = cache[begin];
    if(ret != -1) return ret;

    ret = INF;

    for(int L=3; L<=5; L++)
    {
        if(begin+L <= N.size())
            ret = min(ret, solve(begin+L) + classify(begin, begin+L));
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));
    cout << "ret: " << solve(0);
    return 0;
}