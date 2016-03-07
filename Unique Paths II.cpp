class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(),m = obstacleGrid[0].size();
        int f[n][m];
        memset(f,0,sizeof(f));
        f[0][0] = obstacleGrid[0][0] == 0;
        for(int i = 0;i < n;++i)
            for(int j = 0;j < m;++j){
                if(i == 0 && j == 0 || obstacleGrid[i][j] == 1) continue;
                if(i && !obstacleGrid[i-1][j]) f[i][j] += f[i-1][j];
                if(j && !obstacleGrid[i][j-1]) f[i][j] += f[i][j-1];
            }
        return f[n-1][m-1];
    }
};
