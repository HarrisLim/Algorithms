class Solution {
public:
    int check(int n, vector<int>& memo)
    {
        if(n<=2)
            return n;

        int& ret = memo[n];
        if(ret != -1)
            return ret;

        return ret = check(n-1, memo) + check(n-2, memo);
    }
    int climbStairs(int n) {
        vector<int> memo(46, -1);

        return check(n, memo);
    }
};
