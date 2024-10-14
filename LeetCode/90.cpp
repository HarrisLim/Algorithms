class Solution {
public:
    bool isTheSame(vector<vector<int>>& ret, vector<int>& subV)
    {
        for(int i=0; i<ret.size(); i++)
            if(ret[i] == subV)
                return true;

        return false;
    }
    void backtrack(vector<int>& nums, vector<vector<int>>& ret, vector<int>& subV, int idx)
    {
        if(idx == nums.size())
        {
            if(!isTheSame(ret, subV))
                ret.push_back(subV);
            return;
        }

        if(!isTheSame(ret, subV))
            ret.push_back(subV);

        for(int i=idx; i<nums.size(); i++)
        {
            subV.push_back(nums[i]);
            backtrack(nums, ret, subV, i+1);
            subV.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> subV;
        sort(nums.begin(), nums.end());

        backtrack(nums, ret, subV, 0);

        return ret;
    }
};
