class Solution {
public:
    bool check(const vector<int>& piles, int limit, int k)
    {
        int h=0;
        for(int x: piles)
        {
            h += (x / k);

            if(x % k != 0)
                h++;
        }
        return h <= limit;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while(left<right)
        {
            int mid = left + (right - left) / 2;
            if(check(piles, h, mid))
                right = mid;
            else
                left = mid+1;
        }

        return left;
    }
};
