class Solution {
public:
    // 版本1： 只需要一趟遍历
    int trap(vector<int>& height) {
        int n = height.size();
        if(n <= 1) return 0;
        int l = 0,r = n-1,secHigh = 0,ret = 0;
        while(l < r){
            if(height[l] < height[r]){
                secHigh = secHigh > height[l] ? secHigh : height[l];
                ret += (secHigh - height[l]);
                ++l;
            }
            else{
                secHigh = secHigh > height[r] ? secHigh : height[r];
                ret += (secHigh - height[r]);
                --r;
            }
        }
        return ret;
    }
    // 版本2：两趟遍历，计算每个位置左右(不包括这个位置)的最大值，然后减去当前位置即可
    int trap(vector<int>& height) {
        int n = height.size();
        if(n <= 1) return 0;
        vector<int> leftMaxHeight;
        int lmax = 0;
        for(int i = 0;i < n;++i){
            leftMaxHeight.push_back(lmax);
            lmax = height[i] > lmax ? height[i] : lmax;
        }
        int rmax = 0,ret = 0;
        for(int i = n-1;i >= 0;--i){
            int tmp = min(leftMaxHeight[i],rmax) - height[i];
            if(tmp > 0) ret += tmp;
            rmax = height[i] > rmax ? height[i] : rmax;
        }
        return ret;
    }
};
