class Solution {
public:
    bool backtrack(vector<vector<int>>& visited, vector<vector<char>>& board, string word, int row, int col, int idx)
    {
        if(idx == word.size())
            return true;

        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != word[idx] || visited[row][col] == 1)
            return false;

        visited[row][col] = 1;
        bool res = backtrack(visited, board, word, row-1, col, idx+1)  ||
                    backtrack(visited, board, word, row, col+1, idx+1) ||
                    backtrack(visited, board, word, row+1, col, idx+1) ||
                    backtrack(visited, board, word, row, col-1, idx+1);
        visited[row][col] = -1;
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> visited(board.size(), (vector<int>(board[0].size(), -1)));
        
        int m = board.size();
        int n = board[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(backtrack(visited, board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};
