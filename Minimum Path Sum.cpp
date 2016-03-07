class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        int f[n][m];
        int inf = 1<<30;
        f[0][0] = grid[0][0];
        for(int i = 0;i < n;++i)
            for(int j = 0;j < m;++j){
                if(!i && !j) continue;
                f[i][j] = inf;
                if(i) f[i][j] = min(f[i][j],f[i-1][j]);
                if(j) f[i][j] = min(f[i][j],f[i][j-1]);
                f[i][j] += grid[i][j];
            }
        return f[n-1][m-1];         
    }
};
