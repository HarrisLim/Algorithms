class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> M;
        for(string s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            M[key].push_back(s);
        }
        
        vector<vector<string>> ret;
        for(auto& v : M)
        {
            ret.push_back(v.second);
        }
        return ret;
    }
};
