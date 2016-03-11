class Solution {
public:
    void sortColors(vector<int>& nums) {
        int idx0,idx2,n = nums.size();
        for(idx0 = 0;!nums[idx0];++idx0);
        for(idx2 = n-1;nums[idx2] == 2;--idx2);
        for(int i = idx0;i <= idx2;++i){
            if(!nums[i]) swap(nums[i],nums[idx0++]);
            else if(nums[i] == 2) swap(nums[i--],nums[idx2--]);
            // 注意i--是要继续比较，因为交换过来的可能是0，还要继续交换
            // 0 1 1 0 2 1这种情况
        }    
    }
};
