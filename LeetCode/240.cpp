class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rownum = matrix.size();
        int colnum = matrix[0].size();
        int rowIdx =0;
        int colIdx = colnum-1;

        while(rowIdx < rownum && colIdx >= 0)
        {
            if(matrix[rowIdx][colIdx] == target)
                return true;
            else if(matrix[rowIdx][colIdx] < target)
                rowIdx++;
            else
                colIdx--;
        }
        
        return false;
    }
};

/*
[ 1, 3, 5, 7, 9]
[ 2, 4, 6, 8,10]
[11,13,15,17,19]
[12,14,16,18,20]
[21,22,23,24,25]
*/
