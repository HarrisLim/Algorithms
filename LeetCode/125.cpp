class Solution {
public:
    bool isPalindrome(string s) {
        string removeSL="";
        int n = s.size();

        for(int i=0; i<n; i++)
            if( (s[i] >= 48 && s[i] <= 57) || // number 0~9
                (s[i] >= 65 && s[i] <= 90) || // uppercase A~Z
                (s[i] >= 97 && s[i] <= 122)   ) // lowercase a~z
                    removeSL+=tolower(s[i]);
                
        string toR(removeSL);
        reverse(toR.begin(), toR.end());
        return toR == removeSL;
    }
};
