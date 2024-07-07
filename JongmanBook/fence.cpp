#include <iostream>
#include <vector>

using namespace std;
const vector<int> height = {7, 1, 5, 9, 6, 7, 3};

// in a bruteForce way
int bruteForce()
{
    int ret =0;
    int n = height.size();

    for(int left=0; left<n; left++)
    {
        int minHeight = height[left];
        for(int right=left; right<n; right++)
        {
            minHeight = min(minHeight, height[right]);
            ret = max(ret, (right-left+1)*minHeight);
        }
    }
    return ret;
}

// in a divide & conquer way
int solve(int left, int right)
{
    // base case (there is only one board)
    if(left == right) return height[left];
    // divide
    int mid = (left + right) / 2;
    // search divided boards
    int ret = max(solve(left, mid), solve((mid+1), right));
    // find the biggest board among divided boards
    int lo = mid, hi = mid+1;
    int h = min(height[lo], height[hi]);
    // calculate height[mid, mid+1] and substitute
    ret = max(ret, h*2);
    // calculate till the biggest box
    while(left<lo || hi<right)
    {
        // always search to bigger part
        if(hi<right && (lo == left || height[lo-1] < height[hi+1]))
        {
            hi++;
            h = min(h, height[hi]);
        }
        else
        {
            lo--;
            h = min(h, height[lo]);
        }
        // area of box after expand
        ret = max(ret, h * (hi-lo+1));
    }
    return ret;
}

int main()
{
    // in a bruteForce way
    cout << "ret(1): " << bruteForce() << endl;

    // in a divide & conquer way
    cout << "ret(2): " << solve(0, 6) << endl;
    return 0;
}