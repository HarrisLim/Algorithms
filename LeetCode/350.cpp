class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        unordered_map<int, int> mp;

        for(auto x : nums1)
            mp[x]++;
        
        for(auto x : nums2)
            if(mp.find(x) != mp.end())
                if(mp.find(x)->second > 0 && mp.find(x)->first == x )
                {
                    ret.push_back(x);
                    mp[x]--;
                }

        return ret;
    }
};
