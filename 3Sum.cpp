class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size(),l,r,numl,numr;
        vector<vector<int>> ret;
        if(n < 3) return ret;
        sort(nums.begin(), nums.end());
        for(int i = 0;i < n-2;++i){
            if(i){
                // 去掉与num[i]重复项
                while(i < n-2 && nums[i]==nums[i-1])
                    ++i;
            }
            l = i+1,r = n-1;
            while(l < r){
                if(nums[i]+nums[l]+nums[r]==0){
                    ret.push_back({nums[i],nums[l],nums[r]});
                    // 去掉与num[l]，num[r]重复的数字
                    numl = nums[l],numr = nums[r];
                    while(l < r && nums[l]==numl) ++l;
                    while(l < r && nums[r]==numr) --r;
                }
                else if(nums[i]+nums[l]+nums[r] < 0) ++l;
                else --r;
            }
        }
        return ret;
    }
};
