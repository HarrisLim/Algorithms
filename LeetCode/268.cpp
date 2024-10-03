class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> S(nums.begin(), nums.end());
        
        int ret=0;
        for(int i=0; i<nums.size()+1; i++)
        {
            if(S.find(i) == S.end())
                return ret = i;
        }
        return ret;
    }
};
