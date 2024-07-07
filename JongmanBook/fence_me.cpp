#include <iostream>
#include <vector>

using namespace std;
const vector<int> height = {7, 1, 5, 9, 6, 7, 3};

int bruteforce()
{
    int ret=0;
    int size = height.size();
    
    for(int left=0; left<size; left++)
    {
        int minHeight = height[left];
        for(int right=left; right<size; right++)
        {
            minHeight = min(minHeight, height[right]);
            ret = max(ret, (right-left+1) * minHeight);
        }
    }
    return ret;
}

int solve(int left, int right)
{
    // base case
    if(left == right) return height[left];
    int mid = (left + right) / 2;
    int ret = max(solve(left, mid), solve(mid+1, right));
    int lo = mid, hi = mid+1;
    int h = min(height[lo], height[hi]);

    ret = max(ret, h*2);
    while(left < lo || right > hi)
    {
        if(hi<right && (lo==left || height[lo-1] < height[hi+1]))
        {
            hi++;
            h = min(h, height[hi]);
        }
        else
        {
            lo--;
            h = min(h, height[lo]);
        }
        ret = max(ret, (hi-lo+1)*h);
    }
    return ret;
}

int main()
{
    cout << "ret(1): " << bruteforce() << endl;
    cout << "ret(2): " << solve(0, 6) << endl;
    return 0;
}