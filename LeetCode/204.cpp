class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n+1, true);
        int ret=0;
        isPrime[0] = isPrime[1] = false;

        for(int i=2; i<n; i++)
        {
            if(isPrime[i])
            {
                ret++;
                for(int j=i*2; j<n; j=j+i)
                {
                    isPrime[j]=false;
                }
            }
        }

        return ret;
    }
};
