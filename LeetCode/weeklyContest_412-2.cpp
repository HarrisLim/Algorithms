class Solution {
public:
    bool almostEqual(int x, int y)
    {
        string s1 = to_string(x), s2 = to_string(y);
        int n1 = s1.length(), n2 = s2.length();

        int n = max(n1, n2);
        while(n != n1)
        {
            s1 = "0" + s1;
            n1++;
        }

        while(n != n2)
        {
            s2 = "0" + s2;
            n2++;
        }

        int diff=0;
        unordered_map<char, int> mp1, mp2;
        for(int i=0; i<n; i++)
        {
            diff += (s1[i] != s2[i]);
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }

        return diff <= 2 && mp1 == mp2;
    }

    int countPairs(vector<int>& nums) {
        int c = nums.size();
        int ret=0;
        
        for(int i=0; i<c; i++)
        {
            for(int j=i+1; j<c; j++)
            {
                ret += almostEqual(nums[i], nums[j]);
            }
        }

        return ret;
    }
};
