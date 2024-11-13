class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int prev=0, cur=1;
        int longest_k=0;

        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] > nums[i-1])
            {
                cur += 1;
            }
            else
            {
                prev = cur;
                cur = 1;
            }
            longest_k = max(longest_k, max(cur/2, min(prev, cur)));
        }

        return longest_k >= k;
    }
};
