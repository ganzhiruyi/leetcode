class Solution {
public:
    typedef pair<int,int> pii;
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0; 
        int n = matrix[0].size();
        int f[m][n][2]; 
        f[0][0][0] = f[0][0][1] = matrix[0][0] == '1' ? 1 : 0;
        for(int i = 1;i < m;++i){
            if(matrix[i][0] == '1'){
                f[i][0][0] = 1;
                f[i][0][1] = f[i-1][0][1]+1;
            }
            else{
                f[i][0][0] = f[i][0][1] = 0;
            }
        }
        for(int j = 1;j < n;++j){
            if(matrix[0][j] == '1'){
                f[0][j][0] = f[0][j-1][0]+1;
                f[0][j][1] = 1;
            }
            else{
                f[0][j][0] = f[0][j][1] = 0;
            }
        } 
        for(int i = 1;i < m;++i){
            for(int j = 1;j < n;++j){
                if(matrix[i][j] == '1'){
                    f[i][j][0] = min(f[i-1][j-1][0]+1,f[i][j-1][0]+1);
                    f[i][j][1] = min(f[i-1][j][1]+1,f[i-1][j-1][1]+1);
                }
                else{
                    f[i][j][0] = f[i][j][1] = 0;
                }
            }
        }
        int tmp,ans = 0;
        for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j){
                printf("%d,%d ", f[i][j][0],f[i][j][1]);
                tmp = min(f[i][j][0],f[i][j][1]);
                tmp *= tmp;
                ans = max(ans,tmp);
            }
            printf("\n");
        }
        return ans;
    }
};
