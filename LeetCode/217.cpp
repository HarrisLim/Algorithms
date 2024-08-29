class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int x: nums)
        {
            mp[x]++;
            if(mp.find(x)->second > 1)
                return true;
        }

        return false;
    }
};
