class Solution {
public:
    int countP(string s, char p)
    {
        int cnt=0;
        for(char c : s)
            if(c == p)
                cnt++;

        return cnt;
    }
    void backtrack(int n, vector<string>& ret, string combi, int flag)
    {
        if( countP(combi, '(') < countP(combi, ')') )
            return;
            
        if(combi.length() == n*2)
        {
            ret.push_back(combi);
            return;
        }

        if(countP(combi, '(') < n)
            backtrack(n, ret, combi+'(', 0);

        if(countP(combi, '(') > countP(combi, ')'))
            backtrack(n, ret, combi+')', 0);

    }

    vector<string> generateParenthesis(int n) {
        vector<string> ret;

        backtrack(n, ret, "", 0);

        return ret;
    }
};
