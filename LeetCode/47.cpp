class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& ret, int idx)
    {
        if(nums.size()-1 == idx)
        {
            ret.push_back(nums);
            return;
        }

        unordered_set<int> used;

        for(int i=idx; i<nums.size(); i++)
        {
            if (used.find(nums[i]) != used.end())
                continue;

            used.insert(nums[i]);
            swap(nums[idx], nums[i]);
            backtrack(nums, ret, idx+1);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());

        backtrack(nums, ret, 0);

        return ret;

    }
};
