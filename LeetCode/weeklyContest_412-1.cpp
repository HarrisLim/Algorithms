class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        int c = nums.size();
        while(k--)
        {
            int m=nums[0];
            for(int j=1; j<c; j++)
                m = min(m, nums[j]);

            for(int j=0; j<c; j++)
            {
                if(m == nums[j])
                {
                    nums[j] *= multiplier;
                    break;
                }
            }
        }

        return nums;
    }
};
