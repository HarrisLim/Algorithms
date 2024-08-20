#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

// vector<vector<int>> adj;

int sorting(const vector<int>& perm)
{
    vector<int> sorted = perm;
    sort(sorted.begin(), sorted.end());
    int n = perm.size();

    queue<vector<int>> q;
    map<vector<int>, int> distance;
    distance[perm] = 0;
    q.push(perm);

    // we should keep counting from changed numbers
    while(!q.empty())
    {
        vector<int> here = q.front();
        q.pop();

        if(here == sorted) return distance[here];
        int cost = distance[here];

        for(int i=0; i<n; i++)
        {
            for(int j=i+2; j<=n; j++)
            {
                reverse(here.begin()+i, here.begin()+j);
                if(distance.count(here) == 0)
                {
                    distance[here] = cost+1;
                    cout << i<<":"<<j<< ">> ";
                    for(auto x: here)
                        cout << x << " ";
                    q.push(here);
                    cout << endl;
                }
                // rollback
                reverse(here.begin()+i, here.begin()+j);
            }
        }
    }

    // int cnt=0;
    // for(int i=0; i<n; i++)
    // {
    //     for(int j=i+1; j<n+1; j++)
    //     {
    //         vector<int> temp = perm;
    //         reverse(temp.begin()+i, temp.begin()+j);
    //         cnt++;
    //         cout << i<<":"<<j<< ">> ";
    //         for(auto x: temp)
    //             cout << x << " ";
    //         if(sorted == temp)
    //             return cnt;
    //         cout << endl;
    //     }
    // }

    return -1;
}

int main()
{
    // vector<int> x = {1, 2, 3, 4, 8, 7, 6, 5};
    vector<int> x = {3, 4, 1, 2};

    cout << sorting(x);
    return 0;
}