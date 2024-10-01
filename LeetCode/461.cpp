class Solution {
public:
    int hammingDistance(int x, int y) {
        int n= x ^ y;
        int ret=0;
        while(n>0)
        {
            ret += n%2;
            n/=2;
        }
        return ret;
    }
};
