#include <iostream>

using namespace std;

const int n=5; // depth of well
const int m=5; // the weather condition
int cache[m][m*2-1];

int climb(int days, int climbed)
{
    if(days == m) return climbed >= n ? 1 : 0;

    int& ret = cache[days][climbed];
    if(ret != -1) return ret;

    return ret = climb(days+1, climbed+1) + climb(days+1, climbed+2);
}

int main()
{
    memset(cache, -1, sizeof(cache));

    cout << "ret: " << climb(0,0);
    return 0;
}