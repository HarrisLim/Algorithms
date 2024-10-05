class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        vector<vector<int>> visited = matrix;

        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<columns; j++)
            {
                if(matrix[i][j] == 0)
                {
                    for(int k=0; k<columns; k++)
                        visited[i][k] = 0;
                }
            }
        }

        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<columns; j++)
            {
                if(matrix[i][j] == 0)
                {
                    for(int k=0; k<rows; k++)
                    {
                        visited[k][j] = 0;
                    }
                }
            }
        }

        matrix = visited;        
    }
};
