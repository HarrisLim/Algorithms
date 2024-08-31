class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto x: nums)
            mp[x]++;

        for(auto m : mp)
            if(m.second == 1)
                return m.first;
        
        return 0;
    }
};
