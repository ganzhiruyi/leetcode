class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return true;
        vector<int> f(n,n);
        f[0] = 0;
        int start = 0;
        for(int i = 0;i < n;++i){
            int end = min(i+nums[i],n-1);
            for(int j = start;j <= end;++j)
                f[j] = min(f[j],f[i]+1);
            start = end; 
        }
        cout << f[n-1] << endl;
        return f[n-1] < n;
    }
};
