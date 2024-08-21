#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

map<vector<int>, int> toSort;
// calculate and stores 'toSort[]' for every permutation of [0, ..., n-1]
void precalc(int n)
{
    vector<int> perm(n);
    for(int i=0; i<n; i++)
        perm[i] = i;
    queue<vector<int>> q;
    q.push(perm);
    toSort[perm] = 0;

    while(!q.empty())
    {
        vector<int> here = q.front();
        q.pop();
        int cost = toSort[here];
        for(int i=0; i<n; i++)
        {
            for(int j=i+2; j<=n; j++)
            {
                reverse(here.begin()+i, here.begin()+j);
                if(toSort.count(here) == 0)
                {
                    toSort[here] = cost + 1;
                    q.push(here);
                }
                reverse(here.begin()+i, here.begin()+j);
            }
        }
    }
}
int solve(const vector<int>& perm)
{
    // convert from perm to permutation of [0, ..., n-1]
    int n = perm.size();
    vector<int> fixed(n);
    for(int i=0; i<n; i++)
    {
        int smaller = 0;
        for(int j=0; j<n; j++)
        {
            if(perm[j] < perm[i])
                smaller++;
        }
        fixed[i] = smaller;   
    }
    for(auto x:fixed)
        cout << x << " ";
    return toSort[fixed];
}

int main()
{
    // vector<int> x = {1, 2, 3, 4, 8, 7, 6, 5};
    vector<int> x = {3, 4, 1, 2};

    precalc(4);
    solve(x);
    map<vector<int>, int>::iterator it;
    for(it = toSort.begin(); it != toSort.end(); it++)
    {
        cout << "k: ";
        for(auto k:it->first)
            cout << k << " ";
        cout << "|| v: " << it->second << endl;
    }

    return 0;
}