class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long currentNum = nums[0];
        long long i=0, j=0;
        long long ret=0;

        for(j=1; j<nums.size(); j++)
        {
            if(currentNum < nums[j])
            {
                currentNum = nums[j];
                ret += (j-i) * nums[i];
                i=j;
            }
        }
        if(i != nums.size()-1)
            ret += ((j-1)-i) * nums[i];

        return ret;
    }
};
