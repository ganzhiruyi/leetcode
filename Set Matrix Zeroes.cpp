class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        bool firstRow = false,firstCol = false; // true代表第一行或者第一列为0
        // 然后用第一行存储1-m列是否为0,用第一列存储1-n行是否为0
        for(int i = 0;i < n;++i)
            if(!matrix[i][0]){
                firstCol = true;
                break;
            }
        for(int i = 0;i < m;++i)
            if(!matrix[0][i]){
                firstRow = true;
                break;
            }
        for(int i = 1;i < n;++i)
            for(int j = 1;j < m;++j){
                if(!matrix[i][j])
                    matrix[i][0] = matrix[0][j] = 0;
            }
        for(int i = 1;i < n;++i)
            for(int j = 1;j < m;++j)
                if(!matrix[i][0]) matrix[i][j] = 0;
        for(int j = 1;j < m;++j)
            for(int i = 1;i < n;++i)
                if(!matrix[0][j]) matrix[i][j] = 0;
        if(firstRow)
            for(int i = 0;i < m;++i) matrix[0][i] = 0;
        if(firstCol)
            for(int i = 0;i < n;++i) matrix[i][0] = 0;
    }
};
