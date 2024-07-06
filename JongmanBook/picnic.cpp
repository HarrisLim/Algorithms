#include <iostream>

using namespace std;

/* 
    test case: C( C<=50 ) 
    number of students: n( 2<=n<=10 )
    number of pair: m( 0<=m<=n(n-1)/2 )

*/

const int n=6, m=10;
bool taken[n] = {false, };
bool areFriends[n][n];

int mkFriends(bool taken[])
{
    int firstFree = -1;
    // for order
    for(int i=0; i<n; i++)
    {
        if(!taken[i])
        {
            firstFree = i;
            break;
        }
    }
    if(firstFree == -1) return 1;
    int ret=0;

    for(int pairWith = firstFree+1; pairWith<n; pairWith++)
    {
        if(!taken[pairWith] && areFriends[firstFree][pairWith])
        {
            taken[firstFree] = taken[pairWith] = true;
            ret += mkFriends(taken);
            taken[firstFree] = taken[pairWith] = false;
        }
    }

    return ret;

}

int main()
{
    int result=0;
    // get into friends relations
    areFriends[0][1] = areFriends[0][2] = areFriends[1][2] = areFriends[1][3] = areFriends[1][4] = true;
    areFriends[2][3] = areFriends[2][4] = areFriends[3][4] = areFriends[3][5] = areFriends[4][5] = true; 

    result = mkFriends(taken);
    cout << "최종결과: " << result;
    return 0;
}

/*
    1. make a Array for taken
    2. make and insert information of friend relation.
    3. have to think about order (for example, re-search already searched data)
*/