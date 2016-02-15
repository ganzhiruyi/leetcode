class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return;
        int i,j,ii;
        i = n-1;
        for(;;){
            ii = i;
            --i;
            if(nums[i] < nums[ii]){
                j = n-1;
                while(nums[i] >= nums[j]) --j;
                swap(nums[i],nums[j]);
                reverse(nums.begin()+ii, nums.end());
                return;
            }
            if(i == 0){
                reverse(nums.begin(), nums.end());
                return;
            }
        }
    }
};
