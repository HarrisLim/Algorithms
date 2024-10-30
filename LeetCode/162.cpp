class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int maxNum=INT_MIN;
        int ret=0;

        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i-1] < nums[i])
            {  
                if(maxNum < nums[i])
                {
                    ret = i;
                    maxNum = nums[i];
                }
            }
        }
        return ret;
    }
};
