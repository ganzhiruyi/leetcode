class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //公式C(2n,n)/n+1
        long long ans = 1;
        for(int i = n+2;i<=2*n;i++) ans *= i;
        for(int i = 1;i <= n;i++) ans /= i;
        return ans;
    }
};
