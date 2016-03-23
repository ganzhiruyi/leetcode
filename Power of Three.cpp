class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 1) return false;
        while(n != 1){
            if(n % 3) return false;
            n /= 3;
        }
        return true;
    }
};
class Solution {
public:
    bool isPowerOfThree(int n) {
        /**计算maxPowerOfThree
        int k = 1;
        while(k < INT_MAX/3) k *= 3;
        cout << k << endl;
        **/
        int maxPowerOfThree = 1162261467;
        if(n <= 0) return false;
        return maxPowerOfThree%n == 0;
    }
};
