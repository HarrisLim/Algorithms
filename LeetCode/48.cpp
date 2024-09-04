class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int idx;
        for(int i=n-1; i>=0; i--)
            for(int j=0; j<n; j++)
                matrix[j].push_back(matrix[i][j]);
                
        for(int i=0; i<n; i++)
            matrix[i].erase(matrix[i].begin(), matrix[i].begin()+n);
        
    }
};
