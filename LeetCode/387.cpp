class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size(), ret = -1;
        map<char, int> mp;
        
        for(int i=0 ;i<n; i++)
            mp[s[i]]++;

        while(n>0)
        {
            if(mp[s[n-1]] == 1)
                ret=n-1;
            
            n--;
        }

        return ret;
    }
};
