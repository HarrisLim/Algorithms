/*1672. Richest Customer Wealth*/
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ret=0;
        for(auto i: accounts)
        {
            int sum=0;
            for(auto j: i)
            {
                sum += j;
            }
            ret = max(ret, sum);
        }
        return ret;
    }
};
