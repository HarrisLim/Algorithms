class Solution {
public:
    static bool cmp(pair<string, int> A, pair<string, int> B)
    {
        if(A.second == B.second && A.first < B.first)
            return true;
        return A.second > B.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ret;
        map<string, int> mp;

        for(int i=0; i<words.size(); i++)
            mp[words[i]]++;
        
        vector<pair<string, int>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(), cmp);
        
        for(int i=0; i<k; i++)
            ret.push_back(vec[i].first);
        
        return ret;
    }
};
