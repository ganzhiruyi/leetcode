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
/** In-place 版本,对于原问题[l,r),先将前k个和后k个交换，
然后变成了子问题[l+k,r)，继续交换，直到k%n==0时就可以停止了
**/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(!nums.size()) return;
        int n,l = 0,r = nums.size();
        while(l < r){
            n = r-l;
            k %= n;
            if(k == 0) return;
            for(int i = n-k;i < n;++i)
                swap(nums[i+l],nums[(i+k)%n+l]);
            l += k;
        }
    }
};
