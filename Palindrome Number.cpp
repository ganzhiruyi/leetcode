class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int a = 0,b = x;
        if(x < 0) return false;
        while(b > 0){
            int num = b%10;
            b /= 10;
            a = a*10+num;
        }
        if(a == x) return true;
        return false;
    }
};
