class Solution {
public:
    void backtrack(vector<int>& cand, vector<int>& subV, vector<vector<int>>& ret, int target, int idx)
    {
        if(target == accumulate(subV.begin(), subV.end(), 0))
        {
            ret.push_back(subV);
        }
        else if (target > accumulate(subV.begin(), subV.end(), 0))
        {
            for(int i=idx; i<cand.size(); i++)
            {
                subV.push_back(cand[i]);
                backtrack(cand, subV, ret, target, i);
                subV.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> subV;
        backtrack(candidates, subV, ret, target, 0);

        return ret;
    }
};
