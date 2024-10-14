class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& ret, int idx)
    {
        if(idx == nums.size()-1)
        {
            ret.push_back(nums);
            return;
        }

        for(int i=idx; i<nums.size(); i++)
        {
            cout << idx << " " << i << " " <<nums[idx] << " " << nums[i]<<endl;
            swap(nums[idx], nums[i]);
            backtrack(nums, ret, idx+1);
            swap(nums[idx], nums[i]); // recover swapped number
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;

        backtrack(nums, ret, 0);

        return ret;
    }
};
