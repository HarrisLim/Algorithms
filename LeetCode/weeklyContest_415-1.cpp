class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> M;
        vector<int> mischievousNum;

        for(int i=0; i<nums.size(); i++)
            M[nums[i]]++;


        for(auto it=M.begin(); it!=M.end(); it++)
            if(it->second > 1)
                mischievousNum.push_back(it->first);

        return mischievousNum;        
    }
};
