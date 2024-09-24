class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int profit=0;

        for(int i=0; i<prices.size()-1; i++)
        {
            mini = min(mini, prices[i]);
            if(prices[i+1] > mini)
                profit = max(profit, prices[i+1] - mini);
        }
        return profit;
    }
};
