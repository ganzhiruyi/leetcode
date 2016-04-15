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
// 牛顿迭代法 next = cur/2+x/2/cur
class Solution {
public:
    typedef long long ll;
    int mySqrt(int x) {
        if(x == 0) return 0;
        double cur,next;
        next = 1.0*x;
        do{
            cur = next;
            next = cur/2.0+x/2.0/cur;
        }while(abs(cur-next) > 0.0000001);
        return int(cur);
    }
};
