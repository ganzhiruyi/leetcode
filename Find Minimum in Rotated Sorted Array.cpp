class Solution {
public:
    int findMin(vector<int>& nums) {
        int mid,l = 0,r = nums.size()-1;
        while(l < r){
            mid = l+r>>1;
            if(nums[mid] < nums[r]){
                r = mid;
            }
            else l = mid+1;
        }
        return nums[r];
    }
};
