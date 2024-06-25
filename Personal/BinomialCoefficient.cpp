#include <iostream>
using namespace std;

int factorial(int n)
{
    int result = 1;
    for(int i=1; i<=n; i++)
        result *= i;
    
    return result;
}

int binomialCoefficient(int n, int k)
{
    return factorial(n) / (factorial(k) * factorial(n-k));
}

int main()
{
    int n = 5, k = 2;
    cout << "C(" << n << ", " << k << ") = " << binomialCoefficient(n, k) << endl;
    return 0;
}