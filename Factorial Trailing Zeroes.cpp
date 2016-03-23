class Solution {
public:
    int trailingZeroes(int n) {
        int cntFive = 0;
        while(n){
            n /= 5;
            cntFive += n;
        }
        return cntFive;
    }
};
