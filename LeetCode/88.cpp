class Solution {
public:
// ## Two pointers approach
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int mIdx = m-1;
        int nIdx = n-1;
        int right = m+n-1;

        while(nIdx>=0)
        {
            if(mIdx >= 0 && nums1[mIdx] > nums2[nIdx])
                nums1[right] = nums1[mIdx--];
            else
                nums1[right] = nums2[nIdx--];

            right--;
        }
    }
};

/*
// ## using sort() approach
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0; i<n; i++)
            nums1[m+i] = nums2[i];

        sort(nums1.begin(), nums1.end());
    }
};
*/
