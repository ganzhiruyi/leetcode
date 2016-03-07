// 版本一：直接推出公式为C(n+m-2,n-1),在求C时注意该约分的时候约分
class Solution {
public:
    typedef long long ll;
    int uniquePaths(int m, int n) {
        if(n == 1 || m == 1) return 1;
        ll ret = 1;
        ll up = n+m-2;
        int used[105];
        memset(used,0,sizeof(used));
        for(int i = 1;i <= n-1;i++){
            ret *= up;
            for(int j = n-1;j >= 2;--j){
                if(!used[j] && ret % j == 0){
                    ret /= j;
                    used[j] = 1;
                }
            } 
            --up;
        }
        return ret;
    }
};
// 版本二 dp
class Solution {
public:
    typedef long long ll;
    int uniquePaths(int m, int n) {
        int f[m][n];
        memset(f,0,sizeof(f));
        f[0][0] = 1;
        for(int i = 0;i < m;++i)
            for(int j = 0;j < n;++j){
                if(i == 0 && j == 0) continue;
                if(i) f[i][j] += f[i-1][j];
                if(j) f[i][j] += f[i][j-1];
            }
        return f[m-1][n-1];
    }
};

