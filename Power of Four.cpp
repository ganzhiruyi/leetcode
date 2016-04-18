class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num <= 0) return false;
        if(num&num-1) return false;
        int cnt = 0;
        --num;
        // 判断num-1有奇数个还是偶数个1
        num ^= (num>>1);
        num ^= (num>>2);
        num ^= (num>>4);
        num ^= (num>>8);
        num ^= (num>>16);
        return num&1 ? false : true;
    }
};
