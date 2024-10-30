class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<long long> cnt(26, 0);

        for(char c : s)
            cnt[c-'a']++;

        for(int i=0; i<t; i++)
        {
            vector<long long> temp(26, 0);
            for(int j=0; j<26; j++)
            {
                if(j==25)
                {
                    temp[0] = (temp[0] + cnt[j]) % MOD;
                    temp[1] = (temp[1] + cnt[j]) % MOD;
                }
                else
                {
                    // increse next alphabet
                    temp[j+1] = (temp[j+1] + cnt[j]) % MOD;
                }
            }
            cnt = temp;
        }
        
        long long ret=0;
        for(long long c : cnt)
            ret = (ret + c) % MOD;

        return ret;
    }
};
