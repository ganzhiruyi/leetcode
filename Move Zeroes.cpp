class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0,r = 0;
        while(r < nums.size()){
            if(nums[r]){
                if(!nums[l]) swap(nums[l++],nums[r]);
            }
            else if(nums[l]) l = r;
            ++r;
        }
    }
};
