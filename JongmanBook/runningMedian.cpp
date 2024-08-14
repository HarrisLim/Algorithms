#include <iostream>
#include <vector>

using namespace std;

vector<int> A;

void findMedian(vector<int>& list)
{
    vector<int> v;
    int m;
    for(int i=0; i<list.size(); i++)
    {
        // if(v.size() == list.size()) break;
        v.push_back(list.at(i));
        sort(v.begin(), v.end());
        m = i / 2;
        if(v.size() % 2 == 0 && i>0)
            cout << v.at(m)%20090711 << " ";
        else
            cout << v.at(m)%20090711 << " ";
    }
}

int main()
{
    int c=10, a=1, b=1;
    A.push_back(1983);

    for(int i=1; i<c; i++)
    {
        A.push_back((A[i-1]*a+b) % 20090711);
        // cout << A[i] << " ";
    }
    cout << endl;
    vector<int> temp = {3, 1, 5, 4, 2};
    findMedian(temp);
    // findMedian(A);

    return 0;
}