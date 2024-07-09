#include <iostream>

using namespace std;
/*
this is source about binomial coeffcient
*/
int bino(int n, int r)
{
    // base case: n=r(the case pick every elements) or r=0(the case there isnt any element)
    if(r==0 || n==r) return 1;
    return bino(n-1, r-1) + bino(n-1, r);
}

int main()
{
    cout << "ret: " << bino(3,2) << endl;
    return 0;
}