// 二分的思想,不断找左边l位和右边r位是否为0
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int l,r,bits = 16;
        if(n == INT_MAX || n == INT_MIN) return false;
        while(bits){
            l = n>>bits;
            r = n-(l<<bits);
            if((l && r) || (!l && !r)) return false;
            if(l) n = l;
            else n = r;
            bits >>= 1;
        }
        return true;
    }
};
// 直接利用只有一个1用n&(n-1)，为0则是，否则不是
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n&n-1);
    }
};
