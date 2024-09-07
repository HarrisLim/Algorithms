class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minNum = 987654321;
        string ret="";
        bool isTheSame = false;
        
        if(strs.size() == 1)
            return strs[0];

        // Find the shortest word in strs
        for(auto word : strs)
        {
            int temp = word.length();
            minNum = min(minNum, temp);
        }

        for(int i=0; i<minNum; i++)
        {
            for(int j=0; j<strs.size()-1; j++)
            {
                if(strs[j][i] == strs[j+1][i])
                    isTheSame = true;  
                else
                    return ret;
            }

            if(isTheSame)
                ret+= strs[0][i];
        }

        return ret;
    }
};
