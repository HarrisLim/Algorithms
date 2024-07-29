/*3232. Find if Digit Game Can Be Won*/
class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sDigit=0, dDigit=0, sum=0;
        for(int a : nums)
        {
            if(a<10)
                sDigit+=a;
            else if (a < 100)
                dDigit+=a;

            sum+=a;
        }
        if(sDigit<sum-sDigit || dDigit <sum-dDigit ) return true;
        else return false;
    }
};