class Solution {
public:
    int numSquares(int n) {
        int f[n+1];
        f[0] = 0;
        for(int i = 1;i <= n;++i){
            f[i] = INT_MAX;
            for(int j = 1;j*j <= i;++j)
                f[i] = min(f[i-j*j]+1,f[i]);
        }
        return f[n];        
    }
};

class Solution {
public:
    int numSquares(int n) {
        int f[n+1];
        for(int i = 1;i <= n;++i) f[i] =INT_MAX;
        for(int i = 1;i*i <= n;++i) f[i*i] = 1;
        f[0] = 0;
        for(int i = 1;i <= n;++i){
            for(int j = 1;i+j*j <= n;++j)
                f[i+j*j] = min(f[i]+1,f[i+j*j]);
        }
        return f[n];        
    }
};

