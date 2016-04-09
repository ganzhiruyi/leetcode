class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int f[n][2];
        f[0][0] = f[0][1] = nums[0];
        // f[i][0]表示以nums[i]为子串结尾能得到的最小乘积
        // f[i][1]表示以nums[i]为子串结尾能得到的最大乘积
        for(int i = 1;i < nums.size();++i){
            if(nums[i] < 0){
                f[i][0] = min(f[i-1][1]*nums[i],nums[i]);
                f[i][1] = max(f[i-1][0]*nums[i],nums[i]);
            }
            else{
                f[i][0] = min(f[i-1][0]*nums[i],nums[i]);
                f[i][1] = max(f[i-1][1]*nums[i],nums[i]);
            }
        }
        int ans = f[0][1];
        for(int i = 1;i < n;++i)
            ans = max(ans,f[i][1]);
        return ans;
    }
};
