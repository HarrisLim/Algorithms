class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long left = 1;
        long right = 2 * 1e9;
        long ab = (long)a * (long)b / gcd(a, b);
        long ac = (long)a * (long)c / gcd(a, c);
        long bc = (long)b * (long)c / gcd(b, c);
        long abc = a * bc / gcd(a, bc);

        while(left < right)
        {
            int mid = left + (right - left) / 2;
            long total = mid/(long)a + mid/(long)b + mid/(long)c - mid/ab - mid/ac - mid/bc + mid/abc;
            if(total >= n)
                right = mid;
            else
                left = mid + 1;
        } 

        return left;
    }
};
