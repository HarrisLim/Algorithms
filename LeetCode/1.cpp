class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        /* The first approach */
        // vector<int> ret;
        // // keep order the nums 
        // for(int i=0; i<nums.size(); i++)
        // {
        //     for(int j=i+1; j<nums.size(); j++)
        //     if(nums[i]+nums[j] == target)
        //     {
        //         ret.push_back(i);
        //         ret.push_back(j);
        //         return ret;
        //     }
        // }
        // return ret;

        /* The second approach */
        vector<int> ret;
        unordered_map<int, int> M;
        for(int i=0; i<nums.size(); i++)
        {
            if(M.find(target-nums[i]) != M.end())
            {
                ret.push_back(i);
                ret.push_back(M[target-nums[i]]);  
                return ret;
            }
            M[nums[i]] = i;
        }
        return ret;
    }
};
