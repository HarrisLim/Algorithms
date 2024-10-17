class Solution {
public:
    void backtrack(vector<int>& cand, vector<vector<int>>& ret, vector<int>& sub, int target, int idx)
    {
        if(target == accumulate(sub.begin(), sub.end(), 0))
        {
            ret.push_back(sub);
        }
        else if (target > accumulate(sub.begin(), sub.end(), 0))
        {
            for(int i=idx; i<cand.size(); i++)
            {
                if(i>idx && cand[i] == cand[i-1]) continue;
                {
                    sub.push_back(cand[i]);
                    backtrack(cand, ret, sub, target, i+1);
                    sub.pop_back();
                }
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> sub;
        sort(candidates.begin(), candidates.end());

        backtrack(candidates, ret, sub, target, 0);

        return ret;
    }
};
