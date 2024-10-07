class Solution {
public:
    int expandAroundCenter(string s, int left, int right)
    {
        while(left>=0 && right<s.length() && s[left] == s[right])
        {
            left--; right++;
        }
        return right - left - 1;
    }
    string longestPalindrome(string s) {
        int start=0, end=0;
        for(int i=0; i<s.length(); i++)
        {
            int odd = expandAroundCenter(s, i, i);
            int even = expandAroundCenter(s, i, i+1);
            int max_len = max(odd, even);

            if(max_len > end - start)
            {
                start = i - (max_len-1) / 2;
                end = i + max_len / 2;
            }
        }
        return s.substr(start, end-start+1);
    }
};
/*
I got TLE
class Solution {
public:
    bool isPalindrom(string s)
    {
        int left=0, right=s.length()-1;

        while(left<right)
        {
            if(s[left] != s[right])
                return false;
            left++; right--;
        }

        return true;
    }
    string longestPalindrome(string s) {
        string ret;
        int left=0, max=0;
        for(int left=0; left<s.length(); left++)
        {
            for(int right=left+1; right<s.length()+1; right++)
            {
                string subStr = s.substr(left, right-left);
                if(isPalindrom(subStr))
                {
                    if(max < subStr.length())
                    {
                        max = subStr.length();
                        ret = subStr;
                    }
                }
            }
        }
        return ret;
    }
};
*/
