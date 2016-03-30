// 自己的解法
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int nowbit,bits[32],l = n-m+1;
        memset(bits,0,sizeof(bits));
        for(int i = 0;i < 31;++i){
            nowbit = (n&1)&(m&1); 
            // 当前位与为1且长度不大于2^i，则这一位能得到1
            if(nowbit && l <= (1<<i)) bits[i] = 1; 
            n >>= 1;
            m >>= 1;
            if(!m) break;
        }
        int ret = 0;
        for(int i = 30;i >= 0;--i)
            ret += (bits[i]<<i);
        return ret;        
    }
};
// 其实就是求m,n的高位相同前缀,因为m<n,那么最低位一定可以消去，然后转化为子问题
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int bits = 0;
        while(m < n){
            m >>= 1;
            n >>= 1;
            ++bits;
        }
        return m<<bits;        
    }
};
// 思路同第二种，找到相同的高位前缀,因为m>n时，m在高位一定比n多一个1，利用n&(n-1)消去最低位的1
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while(m < n){
            n = n&(n-1);
        }
        return n;        
    }
};
