class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), k=0;
        unordered_map<int, int> mp;
        vector<int> ret;

        for(int i=0; i<n; i++)
        {
            if(mp[nums[i]]==0)
            {
                mp[nums[i]]++;
                ret.push_back(nums[i]);
                k++;
            }
        }
        nums = ret;
        return k;        
    }
};
