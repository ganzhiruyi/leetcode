class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int start = 0,n = nums.size(),curSum = nums[0];
        int minSum = INT_MAX,minLen = n+1;
        for(int i = 1;i < n;){
            if(curSum >= s){
                minLen = min(minLen,i-start);
                curSum -= nums[start];
                ++start;
            }
            else curSum += nums[i++];
        }
        while(start < n && curSum >= s){
            minLen = min(minLen,n-start);
            curSum -= nums[start];
            ++start;
        }
        return minLen == n+1 ? 0 : minLen;
    }
};
