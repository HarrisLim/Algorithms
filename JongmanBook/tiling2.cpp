#include <iostream>

using namespace std;

const int N=5;
const int MOD = 1000000007;
int cache[101];

int tiling(int n)
{
    // base case
    if(n<=1) return 1;

    int& ret = cache[n];
    if(ret!=-1) return ret;
    
    return ret = (tiling(n-1) + tiling(n-2)) % MOD;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cout << "ret: " << tiling(5); 

    return 0;
}