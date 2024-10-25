class Solution {
public:
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.second > b.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        map<int, int> freq;
        vector<int> ret;
        
        for(int i=0; i<n; i++)
            freq[nums[i]]++;

        vector<pair<int, int>> vec(freq.begin(), freq.end());
        sort(vec.begin(), vec.end(), cmp);

        for(int i=0; i<k; i++)
        {
            ret.push_back(vec[i].first);
        }

        return ret;
    }
};
