#include <iostream>
#include <string>
using namespace std;

int INF=987654321;
// A[]: progrssion for quantization
// pSum[]: store of partial A[] (ex, pSum[i] is sum from A[0] to A[i])
// pSqSum[]: store partil sum of squares of A[].
int n = 9;
int A[101] = {1, 744, 755, 4, 897, 902, 890, 6, 777};
int pSum[101], pSqSum[101];

// order A and calculate each partial sum
void precalc()
{
    sort(A, A+n);
    pSum[0] = A[0];
    pSqSum[0] = A[0] * A[0];
    for(int i=1; i<n; i++)
    {
        pSum[i] = pSum[i-1] + A[i];
        pSqSum[i] = pSqSum[i-1] + A[i] * A[i];
    }
}

// calculate minimum error sum
int minError(int lo, int hi)
{
    // calculate A[lo] ~ A[hi] using pSum
    int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo-1]);
    int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo-1]);

    // round average value
    int m = int(0.5 + (double)sum / (hi-lo+1));

    int ret = sqSum - 2 * m * sum + m * m * (hi-lo+1);
    return ret;
}
int cache[101][11];
int quantize(int from, int parts)
{
    // base case: search every numbers
    if(from == n) return 0;
    // base case: if it cant group, return the large of number
    if(parts == 0) return INF;

    int& ret = cache[from][parts];
    if(ret != -1) return ret;
    ret = INF;

    // find minimum number during changing length of group
    for(int partSize =1; from + partSize<=n; partSize++)
        ret = min(ret, minError(from, from+partSize-1) + quantize(from + partSize, parts-1));

    return ret;
}

int main()
{
    precalc();

    memset(cache, -1, sizeof(cache));
    cout << quantize(0, 3); // choose only 3 of numbers
    return 0;
}