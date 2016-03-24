class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(!nums.size()) return;
        k %= nums.size();
        vector<int> tmp(nums.begin()+n-k,nums.end());
        for(int i = n-k-1;i >= 0;--i)
            nums[i+k] = nums[i];
        for(int i = 0;i < k;++i) nums[i] = tmp[i]; 
    }
};
// In-place 版本
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(!nums.size()) return;
        int n = nums.size();
        k %= n;
        if(k == 0) return;
        while(l < r){
            for(int i = n-k;i < nums.size();++i)
                swap(nums[i],nums[(i+k)%n]);
        }
    }
};
