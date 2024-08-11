/*Q1. Snake in Matrix*/
class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int grid[n][n];
        int idx=0, ret=0, y=0, x=0;

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                grid[i][j] = idx++;

        for(int i=0; i<commands.size(); i++)
        {
            if(commands[i] == "UP")
                y-=1;
            else if(commands[i] == "RIGHT")
                x+=1;
            else if(commands[i] == "DOWN")
                y+=1;
            else if(commands[i] == "LEFT")
                x-=1;
        }

        return grid[y][x];
    }
};

===========================
int y=0, x=0;
        
        for(string s: commands)
        {
            if(s == "UP")
                y--;
            else if(s == "RIGHT")
                x++;
            else if(s == "DOWN")
                y++;
            else if(s == "LEFT")
                x--;
        }
        return y*n+x;