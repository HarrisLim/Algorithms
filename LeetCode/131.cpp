class Solution {
public:
    bool isPalindrome(string s)
    {
        int left = 0;
        int right = s.size()-1;

        while(left < right)
        {
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    void backtrack(vector<vector<string>>& ret, vector<string>& sub, string s, int startIdx)
    {
        if(startIdx >= s.size())
        {
            ret.push_back(sub);
            return;
        }

        for(int i=startIdx; i<s.length(); i++)
        {
            string temp = s.substr(startIdx, i-startIdx+1);
            if(isPalindrome(temp))
            {
                sub.push_back(temp);
                backtrack(ret, sub, s, i+1);
                sub.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> sub;

        backtrack(ret, sub, s, 0);
        
        return ret;
    }
};
