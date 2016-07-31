class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int mid,l = 0,r = nums.size()-1;
        if(r < 0) return false;
        while(l <= r){
            mid = l+(r-l>>1);
            if(nums[mid] == target) return true;
            if(nums[mid] == nums[r]) --r;
            else if(nums[mid] > nums[r]){
                if(target>nums[mid] || target<=nums[r])
                    l = mid+1;
                else r = mid-1;
            }
            else{
                if(nums[mid]<target && target<=nums[r])
                    l = mid+1;
                else r = mid-1;
            }
        }
        return false;
    }
};
