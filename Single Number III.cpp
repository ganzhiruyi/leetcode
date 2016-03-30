class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xory = 0;
        for(int i = 0;i < nums.size();++i) xory ^= nums[i];
        /** 因为其余都是两个出现，所以xory就是x^y的结果,由于x!=y，所以xory一定大于0,
        假设x在某一位(第i位)为1，y在第i位为0，那么就可以按照第i位的0/1把nums分成两组,
        这样就转化成了single Number 1问题,但是怎么选取i了，选取xory中为1的位即可，
        这样再联想到树状数组lowbit(x)快速找到右起第一个1，即可得i
        **/
        int x = 0,y = 0;
        int lowbit = xory&(-xory); // 比如00110->00010(只有一个1)的形式
        for(int i = 0;i < nums.size();++i)
            if(lowbit&nums[i])
                x ^= nums[i];
            else y ^= nums[i];
        vector<int> ret(2);
        ret[0] = x,ret[1] = y;
        return ret;
    }
};
