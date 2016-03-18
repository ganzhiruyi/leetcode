class NumMatrix {
public:
    vector<vector<int>> sums;
    NumMatrix(vector<vector<int>> &matrix) {
        sums.clear();
        if(!matrix.size()) return;
        int n = matrix.size(),m = matrix[0].size();
        for(int i = 0;i < n;++i){
            sums.push_back(vector<int>(m,0));
            for(int j = 0;j < m;++j){
                sums[i][j] = matrix[i][j];
                if(i) sums[i][j] += sums[i-1][j];
                if(j) sums[i][j] += sums[i][j-1];
                if(i && j) sums[i][j] -= sums[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(!sums.size()) return 0;
        int ret = sums[row2][col2];
        if(row1) ret -= sums[row1-1][col2];
        if(col1) ret -= sums[row2][col1-1];
        if(row1 && col1) ret += sums[row1-1][col1-1];
        return ret;
    }
};
