class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size(),l,r,numl,numr,ret;
        if(n < 3) return 0;
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        for(int i = 0;i < n-2;++i){
            l = i+1,r = n-1;
            while(l < r){
                int sum = nums[i]+nums[l]+nums[r];
                if(abs(sum-target) < diff){
                    diff = abs(sum-target);
                    ret = sum;
                }
                if(sum==target)
                    return target;
                else if(nums[i]+nums[l]+nums[r] < target)
                    ++l;
                else --r;
            }
        }
        return ret;
    }
};
