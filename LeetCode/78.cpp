class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& ret, vector<int>& subV, int idx)
    {
        ret.push_back(subV);

        for(int i=idx; i<nums.size(); i++)
        {
            subV.push_back(nums[i]);
            backtrack(nums, ret, subV, i+1);
            subV.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> subV;

        backtrack(nums, ret, subV, 0);

        return ret;
    }
};
