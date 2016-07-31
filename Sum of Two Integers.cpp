class Solution {
public:
    int getSum(int a, int b) {
        int ans = a^b; // 当c等于0时，a+b=a^b
        int c = a&b; // 每个bit的进位
        while(c){ // c存在，a+b=(a^b)+(c<<1),所以可递推下去
            c <<= 1;
            int ans_tmp = ans^c;
            c = ans&c;
            ans = ans_tmp;
        }
        return ans;
    }
};
