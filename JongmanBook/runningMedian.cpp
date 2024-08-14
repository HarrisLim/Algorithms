#include <iostream>
#include <vector>
#include <queue>

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
struct RNG 
{
    int seed, a, b;
    RNG(int _a, int _b) : a(_a), b(_b), seed(1983) {}
    int next()
    {
        int ret = seed;
        seed = ((seed * (long long)a) + b) & 20090711;
        return ret;
    }
};
int runningMedian2(int n, RNG rng)
{
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int ret=0;

    for(int cnt=1; cnt<=n; cnt++)
    {
        if(maxHeap.size() == minHeap.size())
            maxHeap.push(rng.next());
        else
            minHeap.push(rng.next());
        cout << cnt << ": " << minHeap.top() << " ";
        if(!minHeap.empty() && !maxHeap.empty() &&
            minHeap.top() < maxHeap.top())
        {
            int a = maxHeap.top(), b = minHeap.top();
            maxHeap.pop(); minHeap.pop();
            maxHeap.push(b);
            minHeap.push(a);
        }
        ret = (ret + maxHeap.top()) % 20090711;
    }
    return ret;
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

    return 0;
}