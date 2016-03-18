class Solution {
public:
    int reverse(int x) {
        bool negative = false;
        if(x < 0){
            if(x == INT_MIN) return 0;
            negative = true;
            x = -x;
        }
        vector<int> digits;
        while(x){
            digits.push_back(x%10);
            x /= 10;
        }
        int ret = 0;
        for(int i = 0;i < digits.size();++i){
            if(ret < INT_MAX/10 || ret == INT_MAX/10 && digits[i] <= INT_MAX%10){
                ret = ret*10+digits[i];
            }
            else return 0;
        }
        return negative ? -ret : ret;
    }
};
