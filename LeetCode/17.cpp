class Solution {
public:
    void backtrack(const string& digits, int idx, string combi, vector<string>& ret, const unordered_map<char, string>& letters)
    {
        if(idx == digits.length())
        {
            ret.push_back(combi);
            return;
        }

        string l = letters.at(digits[idx]);

        for(char c: l)
            backtrack(digits, idx+1, combi+c, ret, letters);
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if(digits.empty())
            return ret;

        unordered_map<char, string> letters = 
        {     {'2', "abc"}
            , {'3', "def"}
            , {'4', "ghi"}
            , {'5', "jkl"}
            , {'6', "mno"}
            , {'7', "pqrs"}
            , {'8', "tuv"}
            , {'9', "wxyz"}
        };

        backtrack(digits, 0, "", ret, letters);

        return ret;
    }
};
