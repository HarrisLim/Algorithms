class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        
        for(int i=0; i<numRows; i++)
        {
            vector<int> tempVector;
            for(int j=0; j<i+1; j++)
            {
                if(j==0 || j==i)
                    tempVector.push_back(1);
                else
                    tempVector.push_back(ret[i-1][j-1]+ret[i-1][j]);
            }
            ret.push_back(tempVector);
        }
        
        return ret;
    }
};
