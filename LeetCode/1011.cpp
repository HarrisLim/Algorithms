class Solution {
public:

    bool check(const vector<int>& weights, int capacity, int D)
    {
        int days = 1;
        int total = 0;

        for(int w : weights)
        {
            total += w;
            if(total > capacity)
            {
                total = w;
                days++;
                if(days > D)
                    return false;
            }
        }
        return true; 
    }

    int shipWithinDays(vector<int>& weights, int days) {
        /*  1. shouldn't binary search be in ascending order?
            2. how can I get the left or right value ?  using index?
            3. How can I make the condition?
        */
        // find max value in weights
        int left = *max_element(weights.begin(), weights.end());
        // sum every numbers
        int right = accumulate(weights.begin(), weights.end(), 0);

        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(check(weights, mid, days))
                right = mid;
            else
                left = mid+1;
        }

        return left;
    }
};
