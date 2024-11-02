class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int left = 0;
        int right = mat[0].size()-1;

        while(left <= right)
        {
            int maxIdx = 0;
            int mid = left + (right - left) / 2;
            cout << mid<<endl;

            for(int i=0; i<mat.size(); i++)
                if(mat[i][mid] > mat[maxIdx][mid])
                    maxIdx = i;
            
            bool leftIsBig = mid-1 >= left && mat[maxIdx][mid-1] > mat[maxIdx][mid];
            bool rightIsBig = mid+1 <= right && mat[maxIdx][mid+1] > mat[maxIdx][mid];
            
            if(!leftIsBig && !rightIsBig)
                return vector<int>{maxIdx, mid};
            else if(leftIsBig)
                right = mid;
            else
                left = mid+1;
        }

        return {-1, -1};
    }
};
