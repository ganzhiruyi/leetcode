class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i = 0;i < nums.size();i++)
            if(nums[i] >= target) return i;
        return nums.size();
    }
};
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int mid,l = 0,r = nums.size()-1;
        while(l < r){
            mid = l+(r-l>>1);
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) r = mid;
            else l = mid+1;
        }
        return nums[r] > target ? r : r+1;
    }
};
