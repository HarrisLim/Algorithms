/*3233. Find the Count of Numbers Which Are Not Special*/
class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int sum=0;
        
        for(; l<=r; l++)
        {
            if(l <= 10 && l==4 || l==9) continue;
            else sum++;
        }

        return sum;
    }
};
