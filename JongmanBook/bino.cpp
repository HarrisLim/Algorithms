#include <iostream>
#include <vector>

using namespace std;

int cache[30][30];

// this is source about binomial coeffcient with dup exploring
int bino(int n, int r)
{
    // base case: n=r(the case pick every elements) or r=0(the case there isnt any element)
    if(r==0 || n==r) return 1;
    return bino(n-1, r-1) + bino(n-1, r);
}

// solve with memoization
int binoMemo(int n, int r)
{
    if(r==0 || n==r) return 1;
    if(cache[n][r] != 0)
    {
        return cache[n][r];
    }
    
    return cache[n][r] = binoMemo(n-1, r-1) + binoMemo(n-1, r);
}

int main()
{
    cout << "ret_1: " << bino(4,2) << endl;
    cout << "ret_2: " << binoMemo(4,2) << endl;
    return 0;
}