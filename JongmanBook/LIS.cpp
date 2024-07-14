#include <iostream>
#include <string>
#include <vector>

using namespace std;

int lis(const vector<int>& A)
{
    // base case
    if(A.empty()) return 0;
    int ret=0;
    for(int i=0; i<A.size(); i++)
    {
        vector<int> B;
        for(int j=i+1; j<A.size(); j++)
        {
            if(A[i] < A[j])
            {
                B.push_back(A[j]);
            }
        }
        ret = max(ret, 1+lis(B));
    }
    return ret;
}

//using memoization
int n=5;
int cache[100], S[100] = {1, 5, 2, 4, 7};
int lis2(int start)
{
    int& ret = cache[start];
    if(ret != -1) return ret;
    
    ret =1;
    for(int next=start+1; next<n; next++)
        if(S[start] < S[next])
            ret = max(ret, lis2(next)+1);

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    // vector<int> A = {1, 3, 4, 2, 4};
    vector<int> A = {1, 5, 2, 4, 7};
    cout << "ret_1: " << lis(A) << endl;;

    int maxLen=0;
    for(int begin=0; begin<n; begin++)
        maxLen = max(maxLen, lis2(begin));
    cout << "ret_2: " << maxLen;

    return 0;
}