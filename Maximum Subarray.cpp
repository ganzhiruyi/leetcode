class Solution {
public:
    const int inf = 1<<30;
    int maxSubArray(vector<int>& nums) {
        int maxSum = -inf,curSum = 0;
        for(int i = 0;i < nums.size();++i){
            curSum += nums[i];
            if(maxSum < curSum) maxSum = curSum;
            if(curSum < 0) curSum = 0;
        }
        return maxSum;
    }
    
};
