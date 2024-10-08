class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int max1 = INT_MAX;
        int max2 = INT_MAX;

        for(int n : nums)
        {
            if(n <= max1)
                max1 = n;
            else if(n <= max2)
                max2 = n;
            else
                return true;
        }
        return false;
    }
};
