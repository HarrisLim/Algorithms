class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> columns[9];
        unordered_set<char> subBox[9];

        for(int r=0; r<9; r++)
        {
            for(int c=0; c<9; c++)
            {
                if(board[r][c] == '.')
                    continue;
                
                int value = board[r][c];
                int boxIdx = (r/3) * 3 + (c/3);

                if(rows[r].count(value) || columns[c].count(value) || subBox[boxIdx].count(value))
                    return false;
                
                rows[r].insert(value);
                columns[c].insert(value);
                subBox[boxIdx].insert(value);
            }
        }
        return true;
    }
};
