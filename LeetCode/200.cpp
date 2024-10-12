class Solution {
public:
    void helper(vector<vector<char>>& grid, vector<vector<int>>& visited, int y, int x) 
    {
        // if exceed of grid site.
        if(y < 0 || x < 0 || y > grid.size()-1 || x > grid[0].size()-1)
            return;

        // if already visited island
        if(grid[y][x] == '0' || visited[y][x] == 1)
            return;

        visited[y][x] = 1;

        // left
        helper(grid, visited, y, x-1);
        // top
        helper(grid, visited, y-1, x);
        // right
        helper(grid, visited, y, x+1);
        // bottom
        helper(grid, visited, y+1, x);
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), -1));
        int ret=0;

        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j]=='1' && visited[i][j] == -1)
                {
                    ret++;
                    helper(grid, visited, i, j);
                }
            }
        }

        return ret;
    }
};
