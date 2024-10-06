class Solution {
public:
    string toBinary(int n)
    {    
        string str="";
        while(n>0)
        {
            str += to_string(n%2);
            n/=2;
        }
        reverse(str.begin(), str.end());
        return str;
    }
    int maxGoodNumber(vector<int>& nums) {
        vector<string> strNums(3);
        for(int i=0; i<3; i++)
            strNums[i] = toBinary(nums[i]);

        string tempRet="";
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                for(int k=0; k<3; k++)
                {
                    if(i!=j && j!=k && k!=i)
                    {
                        string combine = strNums[i] + strNums[j] + strNums[k];
                        tempRet = max(tempRet, combine);
                    }
                }
            }
        }
        int ret = stoi(tempRet, nullptr, 2);
        return ret;
    }
};
