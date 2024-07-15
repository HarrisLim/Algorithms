#include <iostream>

using namespace std;

// test case 1
int A[100] = {1, 2, 4};
int B[100] = {3, 4, 7};
// test case 2
// int A[100] = {1, 2, 3};
// int B[100] = {4, 5, 6};
// test case 3
// int A[100] = {10, 20, 30, 1, 2};
// int B[100] = {10, 20, 30};

const long long NEGINF = numeric_limits<long long>::min();
int n=3, m=3;
int cache[101][101];

int jlis(int indexA, int indexB)
{
    // memoization
    int& ret = cache[indexA+1][indexB+1];
    if(ret != -1) return ret;

    ret=2;
    long long a = (indexA == -1 ? NEGINF : A[indexA]);
    long long b = (indexB == -1 ? NEGINF : B[indexB]);
    long long maxElement = max(a,b);

    // find next elements
    for(int nextA = indexA + 1; nextA<n; nextA++)
        if(maxElement < A[nextA])
            ret = max(ret, jlis(nextA, indexB)+1);
    for(int nextB = indexB + 1; nextB<m; nextB++)
        if(maxElement < B[nextB])
            ret = max(ret, jlis(indexA, nextB)+1);
    
    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cout << "ret: " << jlis(-1, -1);

    return 0;
}