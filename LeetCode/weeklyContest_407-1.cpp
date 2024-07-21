/*100372. Number of Bit Changes to Make Two Integers Equal Solve*/
class Solution {
public:
    int minChanges(int n, int k) {
        if(n < k || ((n-k) == 1 && k%2!=0)) return -1;
        
        int ret=0; 

        vector<int> BinN;
        vector<int> BinK;
        
        while(n/2 != 0)
        {
            BinN.push_back(n%2);
            n /= 2;
        }
        BinN.push_back(1);

        while(k/2 != 0)
        {
            BinK.push_back(k%2);
            k /= 2;
        }
        BinK.push_back(1);

        int num = BinN.size() - BinK.size();
        for(int i=0; i<num; i++)
            BinK.push_back(0);

        for(int i=0; i<BinN.size(); i++)
        {
            if(BinN.at(i) == 1 && BinN.at(i) != BinK.at(i))
                ret++;
            if(BinN.at(i) == 0 && BinK.at(i) == 1)
                return -1;
        }
        
        return ret;
    }
};