#include <iostream>

using namespace std;

const int n=6;
int MOD=1000000007;
int cache[101];

int asymTiling(int idx)
{
    // base case
    if(idx <= 1) return 1;
    // i believe it would be enough only one if condition!!!
    // even if idx==n, symmetry tiles then,,,,, what condition should I add ?

    int& ret = cache[idx];
    if(ret != -1) return ret;

    ret = (asymTiling(idx-1)+asymTiling(idx-2)) % MOD;
    // ret is just count the number of cases.
    // how can I find that specific time make asymmetry tiles
    //   ㄴ> but I guess, I dont find the time. 
    // perhaps just add a if condition?
    // cout << "ret["<<idx<<"]: " << ret << endl;
    return ret;
}

int asymmetric(int width)
{
    // if odd,
    if(width%2 == 1)
        return (asymTiling(width) - asymTiling(width/2) + MOD) % MOD;

    // if even
    int ret = asymTiling(width);
    ret = (ret - asymTiling(width/2) + MOD) % MOD;
    // cout << "ret1_inFunc: " << ret << " ";
    ret = (ret - asymTiling(width/2-1) + MOD) % MOD;
    // cout << "ret2_inFunc: " << ret << " ";
    return ret;
}

// asymmetric2 is that calcuating from both side
int cache2[101];
int asymmetric2(int width)
{
    // base case
    if(width <= 2) return 0;

    // memoization
    int& ret = cache2[width];
    if(ret != -1) return ret;

    ret = asymmetric2(width-2) % MOD;
    ret = (ret + asymmetric2(width-4)) % MOD; 
    ret = (ret + asymTiling(width-3)) % MOD;
    ret = (ret + asymTiling(width-3)) % MOD;
    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));
    cout << "ret: " << asymTiling(n) << endl;
    memset(cache, -1, sizeof(cache));
    cout << "asymmetric: " << asymmetric(n) << endl;
    
    memset(cache2, -1, sizeof(cache2));
    cout << "asymmetric2: " << asymmetric2(n);
    return 0;
}