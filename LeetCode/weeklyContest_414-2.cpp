class Solution {
    public: 
    bool check(const vector<int>& start, int d, int mid)
    {
        int prev = start[0];
        for(int i=1; i<start.size(); i++)
        {
            if(start[i] + d - prev < mid)
                return false;
            prev = max(start[i], prev + mid);
        }
        return true;
    }

    int maxPossibleScore(vector<int>& start, int d) {
        int n = start.size();
        sort(start.begin(), start.end());
        int left = 0;
        int right = start.back()-start.front() + d + 1;

        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(check(start, d, mid))
                left = mid + 1;
            else
                right = mid;
            // cout << "mid:" <<mid << " left:" << left << " right:"<<right<<endl;
        }

        return left - 1;
    }
};
