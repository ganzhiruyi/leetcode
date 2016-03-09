class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        int i = 0,j = 0,left = 0;
        while(i < n && j < m){
            if(!matrix[i][j]){
                for(int k = 0;k < n;++k) matrix[k][j] = 0;
                for(int k = 0;k < m;++k) matrix[i][k] = 0;
                ++i,++j;
                left = j;
            }
            else{
                ++j;
                if(j == m && i < n){
                    j = left;
                    ++i;
                }
            }
        }
    }
};
