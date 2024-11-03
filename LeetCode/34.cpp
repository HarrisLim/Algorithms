class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool isFindingLast)
    {
        int left = 0;
        int right = nums.size()-1;
        int ret=-1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;

            if(nums[mid] == target)
            {
                ret=mid;
                isFindingLast ?  left = mid+1 : right = mid-1;
            }
            else if(nums[mid] > target)
                right = mid-1;
            else
                left = mid+1;
        }
        return ret;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstIdx = binarySearch(nums, target, false);
        int lastIdx = binarySearch(nums, target, true);

        return vector<int>{firstIdx, lastIdx};
    }
};
