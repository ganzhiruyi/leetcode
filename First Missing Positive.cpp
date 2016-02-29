class Solution {
public:
    /*这个题把对应的数字放到对应的[0,n)位置上，然后找出不对应的*/
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size() == 0) return 1;
        int n = nums.size(),i = 0;
        while(i < n){
            if(nums[i]!=i+1 && nums[i]>=1 && nums[i]<=n && nums[nums[i]-1]!=nums[i])
                swap(nums[i],nums[nums[i]-1]);
            else ++i;
        }
        for(int i = 0;i < n;++i)
            if(nums[i] != i+1) return i+1;
        return n+1;
    }
};
