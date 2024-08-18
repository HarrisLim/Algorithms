/*3258. Count Substrings That Satisfy K-Constraint I*/
class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int ret=0, n=s.size();

        for(int i=0; i<n; i++)
        {
            int x=0, y=0;
            for(int j=i; j<n; j++)
            {
                (s[j] == '0' ? x : y)++;
                if(x<=k || y<=k)
                    ret++;
            }
        }
        return ret;
    }
};