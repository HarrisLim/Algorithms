class Solution {
public:
    bool check(int h, const vector<int>& times, long long limit)
    {
        long long sum=0;

        for(int t : times)
        {
            long long left = 0, right = h;
            while(left < right)
            {
                long long mid = left + (right-left+1) / 2;
                if((t * mid * (mid + 1)) / 2 > limit)
                    right = mid-1;
                else
                    left = mid;
            }

            sum += left;
        }
        
        return sum >= h;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left =1;
        long long right = LONG_MAX;

        while(left<right)
        {
            long long mid = left + (right-left) /2;
            if(check(mountainHeight, workerTimes, mid))
                right = mid;
            else
                left = mid+1;
        }

        return left;
    }
};
