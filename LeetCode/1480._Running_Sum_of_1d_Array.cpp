/*1480. Running Sum of 1d Array*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ret;
        ret.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++)
            ret.push_back(ret[i-1] + nums[i]);
            
        return ret;
    }
};

int main()
{
    vector<int> nums = {1,2,3,4};

    Solution sol;

    vector<int> ret = sol.runningSum(nums);

    for(auto num : ret)
        cout << num << " ";

    return 0;
}