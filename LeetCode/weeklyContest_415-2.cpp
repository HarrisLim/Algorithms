class Solution {
public:
    long long solve(const vector<int>& a, const vector<int>& b, int i, int j, vector<vector<long long>>& dp)
    {
        if(i == 4)
            return 0;
        if(j >= b.size() )
            return INT_MIN;

        // memoization
        if(dp[i][j] != -1)
            return dp[i][j];
        
        long long take = (long long)a[i] * b[j] + solve(a, b, i+1, j+1, dp);
        long long notTake = solve(a, b, i, j+1, dp);

        return dp[i][j] = max(take, notTake);
    }

    long long maxScore(vector<int>& a, vector<int>& b) {
        
        vector<vector<long long>> dp(4, vector<long long>(b.size(), -1));

        return solve(a, b, 0, 0, dp);
    }
};
