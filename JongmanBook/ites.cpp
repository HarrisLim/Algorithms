#include <iostream>
#include <vector>

using namespace std;

int simple(const vector<int>& signals, int k)
{
    int ret=0;
    for(int head=0; head<signals.size(); head++)
    {
        int sum=0;
        for(int tail=head; tail<signals.size(); tail++)
        {
            sum+=signals[tail];
            if(sum==k) ret++;
            if(sum>=k) break;
        }
    }
    return ret;
}

int optimized(const vector<int>& signals, int k)
{
    int ret=0, tail=0, rangeSum=signals[0];
    for(int head=0; head<signals.size(); head++)
    {
        while(rangeSum < k && tail+1 < signals.size())
            rangeSum += signals[++tail];

        if(rangeSum == k) ret++;

        rangeSum -= signals[head];
    }
    return ret;
}

int main()
{
    int k = 8791;
    int n = 20;
    vector<int> vx;
    for(int i=1; i<=n; i++)
    {
        vx.push_back(i);
    }

    cout << "ret_1: " << simple(vx, k) << endl;
    cout << "ret_2: " << optimized(vx, k) << endl;

    return 0;
}