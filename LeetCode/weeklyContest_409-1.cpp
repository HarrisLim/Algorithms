/*3242. Design Neighbor Sum Service*/
class neighborSum {
public:
    vector<vector<int>> localGrid;
    int pY=-1, pX=-1;

    neighborSum(vector<vector<int>>& grid) {
        localGrid = grid;
    }
    void findIdx(int value)
    {
        pY=-1, pX=-1;
        for(int y=0; y<localGrid.size(); y++)
            for(int x=0; x<localGrid.size(); x++)
                if(localGrid[y][x] == value)
                {
                    pY = y;
                    pX = x;
                    break;
                }

    }
    int adjacentSum(int value) {

        int sum=0;
        findIdx(value);

        if(pY != 0) sum += localGrid[pY-1][pX];
        if(pX != 0) sum += localGrid[pY][pX-1];
        if(pX<localGrid.size()-1) sum += localGrid[pY][pX+1];
        if(pY<localGrid.size()-1)sum += localGrid[pY+1][pX];

        return sum;        
    }
    
    int diagonalSum(int value) {
        int sum=0;
        findIdx(value);
        
        if(pY != 0 && pX != 0) sum += localGrid[pY-1][pX-1];
        if(pY != 0 && pX <localGrid.size()-1) sum += localGrid[pY-1][pX+1];
        if(pY <localGrid.size()-1 && pX != 0) sum += localGrid[pY+1][pX-1];
        if(pY <localGrid.size()-1 && pX <localGrid.size()-1) sum += localGrid[pY+1][pX+1];

         return sum;        
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */