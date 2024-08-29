class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> v;
        int n = nums.size();
        // The starting index should vary depending on the size of k and n.
        int c = k>=n ? n-k%n : n-k;

        for(int i=c; i<n; i++)
            v.push_back(nums[i]);

        int vn=v.size();
        for(int i=0; i<n-vn; i++)
            v.push_back(nums[i]);

        nums = v;

        /* TIME LIMIET*/
        // long x;
        // while(k--)
        // {
        //     x = nums.back();
        //     nums.pop_back();
        //     nums.insert(nums.begin(), x);
        // }
    }
};
