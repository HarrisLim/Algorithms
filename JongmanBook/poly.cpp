#include <iostream>

using namespace std;
const int N = 4;

int polyMe(int h)
{
    //base case 
    if(h <= 0) return 1;

    int ret = 0;
    // cout << "h: " << h << "  ";
    // cout << "ret: " << (h*2*(N-h)) << endl;
    ret = polyMe(h-1);
    // cout << "retret: " << ((h) * 2 * (N-h)) << "h:"<< h << endl;
    return ret = (h * 2 * (N-h));

    // however, I think This is not an answer.
    // I should find another way
}

const int MOD = 100000007;
int cache[101][101];
int poly(int n, int first)
{
    // base case
    if(n == first) return 1;

    // memoization
    int& ret = cache[n][first];
    if(ret != -1) return ret;
    ret =0;

    for(int second=1; second<=n-first; second++)
    {
        int add = second + first -1;
        add *= poly(n-first, second);
        add %= MOD;
        ret += add;
        ret %= MOD;
    }
    return ret;
}

int main()
{
    cout << "ret_me: " << polyMe(N) << endl;
    memset(cache, -1, sizeof(cache));
    cout << "ret_Jong: " << poly(N, 1) << endl;

    return 0;
}