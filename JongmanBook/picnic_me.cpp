#include <iostream>

using namespace std;

const int n=6, m=10;
bool taken[6] = {false, };
int areFriends[n][n];

int mkFriends(bool taken[])
{
    int firstFree = -1;
    for(int i=0; i<n; i++)
    {
        if(!taken[i])
        {
            firstFree = i;
            break;
        }
    }
    if(firstFree == -1) return 1;

    int ret = 0;
    for(int pairWith = firstFree+1; pairWith<6; pairWith++)
    {
        if(!taken[pairWith] && areFriends[firstFree][pairWith])
        {
            taken[pairWith] = taken[firstFree] = true;
            ret += mkFriends(taken);
            taken[pairWith] = taken[firstFree] = false;
        }   
    }
    return ret;
}

int main()
{
    // insert relations of friends
    areFriends[0][1] = areFriends[0][2] = areFriends[1][2] = areFriends[1][3] = areFriends[1][4] = true;
    areFriends[2][3] = areFriends[2][4] = areFriends[3][4] = areFriends[3][5] = areFriends[4][5] = true;

    cout << "result: " << mkFriends(taken);

    return 0;
}
