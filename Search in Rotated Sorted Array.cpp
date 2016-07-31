class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int mid,l = 0,r = n-1,pivot = -1;
        if(nums[0] > nums[n-1]){ // 存在Rotate
            while(l <= r){
                mid = l+r>>1;
                if(nums[mid] >= nums[0]){
                    l = mid+1;
                    pivot = max(pivot,mid);
                }
                else r = mid-1;
            }
        }
        if(pivot == -1){
            l = 0,r = n-1;
        }
        else{
            if(target == nums[0]) return 0;
            if(target > nums[0]){
                l = 0,r = pivot;
            }
            else{
                l = pivot+1,r = n-1;
            }
        }
        while(l <= r){
            mid = l+r>>1;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) r = mid-1;
            else l = mid+1;
        }
        return -1;
    }
};
// 版本二，不用找到pivot
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int mid,l = 0,r = n-1;
        while(l <= r){
            mid = l+(r-l>>1);
            if(nums[mid] == target) return mid;
            else if(nums[mid] > nums[r]){
                if(target>nums[mid] || target<=nums[r])
                    l = mid+1;
                else r = mid-1;
            }
            else{
                if(target>nums[mid] && target<=nums[r])
                    l = mid+1;
                else r = mid-1;
            }
        }
        return -1;
    }
};




