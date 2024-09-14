class Solution {
public:
    bool check(const vector<int>& nums, int limit, int mid)
    {
        int sum=0;
        for(int x : nums)
        {
            sum += (x / mid);
            if(x % mid != 0)
                sum++;
        }
        return sum <= limit;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(check(nums, threshold, mid))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};
