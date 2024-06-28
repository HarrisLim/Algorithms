#include <iostream>

using namespace std;

int sum(int n)
{
    int ret=0;
    for(int i=1; i<=n; i++)
        ret += i;
    return ret;
}

int recursiveSum(int n)
{
    int ret=0;
    if(n==1) return 1;

    ret += recursiveSum(n-1);
    return ret+n;
}

int recursiveSumJM(int n)
{
    if(n==1) return 1;
    return n + recursiveSumJM(n-1);
}

int main()
{
    cout << "sum: " << sum(5)<< "\n";
    cout << "recursiveSum: " << recursiveSum(5)<< "\n";
    cout << "recursiveSumJM: " << recursiveSumJM(5)<< "\n";
    return 0;
}