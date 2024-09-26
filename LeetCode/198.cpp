class Solution {
public:
    int dp(const vector<int>& nums, int i, vector<int>& memo)
    {
        if(i < 0)
            return 0;

        int &ret = memo[i];
        if(ret != -1)
            return ret;

        return ret = max(dp(nums, i-2, memo) + nums[i], dp(nums, i-1, memo));
    }
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return dp(nums, nums.size()-1, memo);
    }
};
