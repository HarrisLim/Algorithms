class Solution {
public:
    bool check(const vector<int>& bloomDay, int bouquets, int flowers, int mid)
    {
        int adjF=0;
        int cnt=0;

        for(int d : bloomDay)
        {
            if(d > mid)
                adjF =0;
            else
            {
                cnt += (adjF+1) / flowers;
                adjF = (adjF+1) % flowers;
            }
        }
        
        return cnt >= bouquets;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < (long)m*k)
            return -1;

        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());

        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(check(bloomDay, m, k, mid))
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
};
