class Solution {
public:
    int rob(vector<int>& nums) {
        if(!nums.size()) return 0;
        int f[nums.size()][2];
        f[0][0] = 0,f[0][1] = nums[0];
        for(int i = 1;i < nums.size();++i){
            f[i][0] = max(f[i-1][0],f[i-1][1]);
            f[i][1] = f[i-1][0]+nums[i];
        }
        return max(f[nums.size()-1][0],f[nums.size()-1][1]);
    }
};
