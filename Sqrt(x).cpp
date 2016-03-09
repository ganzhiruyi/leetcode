class Solution {
public:
    typedef long long ll;
    int mySqrt(int x) {
        if(x <= 1) return x;
        ll mid,l = 1,r = x,ret = 0;
        while(l <= r){
            mid = (l+r)>>1;
            ll tmp = mid*1LL*mid;
            if(tmp <= x){
                l = mid+1;
                ret = max(ret,mid);
            }
            else r = mid-1;
        }
        return ret;
    }
};
