class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> S;
        int left = 0, ret = 0;

        for(int right=0; right<s.length(); right++)
        {
            while(S.find(s[right]) != S.end())
            {
                S.erase(s[left]);
                left++;
            }

            S.insert(s[right]);
            ret = max(ret, (int)S.size());
        }
        return ret;
    }
};
