class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int ret=0;
        
        for(int i=0; i<s.length(); i++)
        {
            vector<int> freq(26, 0);
            for(int j=i; j<s.length(); j++)
            {
                freq[s[j]-'a']++;
                if(freq[s[j]-'a'] >= k)
                {
                    ret+= s.length() - j;
                    break;
                }
            }
        }
        return ret;
    }
};
