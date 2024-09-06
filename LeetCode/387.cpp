class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size(), ret = -1;
        unordered_map<char, int> mp;

        for(int i=0 ;i<n; i++)
            mp[s[i]]++;

        for(int i=0; i<n; i++)
            if(mp[s[i]] == 1)
                return i;

        return ret;
    }
};
