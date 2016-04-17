class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int mid,l = 0,r = nums.size()-1;
        while(l < r){
            mid = l+r>>1;
            if(nums[mid] <= nums[r])
                l = mid+1;
            else r = mid;
        }
        return r;
    }
};
