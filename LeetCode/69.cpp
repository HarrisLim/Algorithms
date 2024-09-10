class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1)    
            return x;

        int left = 0;
        int right = x;
        while(left < right)
        {
            int mid = left + (right-left) / 2;
            if ((long)mid * mid > x)
                right = mid;
            else
                left = mid +1;
            idx++;
        }

        return left -1;
    }
};
