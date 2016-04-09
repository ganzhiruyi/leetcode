class Solution {
public:
    int nthUglyNumber(int n) {
        /**
        思路：构造三个数组
        2*1,2*2,2*3,2*4,2*5,2*6,2*8...
        3*1,3*2,3*3,3*4,3*5,3*6,3*8...
        5*1,5*2,5*3,5*4,5*5,5*6,5*8...
        f[0],f[1],f[2]表示当前乘以2,3,5的数组的下标移动到的位置
        uglyNum存储当前的ugly数，相当于一个三路合并操作
        **/
        int f[3],uglyNum[n],uglyNumCnt = 1;
        uglyNum[0] = 1;
        f[0] = f[1] = f[2] = 0;
        while(uglyNumCnt < n){
            int a = 2*uglyNum[f[0]];
            int b = 3*uglyNum[f[1]];
            int c = 5*uglyNum[f[2]];
            int t = min(a,min(b,c));
            int preUgly = uglyNum[uglyNumCnt-1];
            if0l(t > preUgly) // 注意可能已经t出现过,所以要保证t > preUgly
                uglyNum[uglyNumCnt++] = t;
            if(a == t) ++f[0];
            else if(b == t) ++f[1];
            else ++f[2];
        }
        return uglyNum[n-1];        
    }
};
