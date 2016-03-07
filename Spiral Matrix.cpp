class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> ret;
        if(matrix.size() == 0) return ret;
        int m = matrix.size(),n = matrix[0].size();
        int x1 = 0,y1 = 0,x2 = m-1,y2 = n-1;
        while(x1<=x2 && y1<=y2){
            for(int i = y1;i <= y2;++i) ret.push_back(matrix[x1][i]);   // up row
            for(int i = x1+1;i <= x2;++i) ret.push_back(matrix[i][y2]); // right col
            if(x1 != x2) // 如果只有一行，up row已经遍历了行
                for(int i = y2-1;i >= y1;--i) ret.push_back(matrix[x2][i]); // bottom row 
            if(y1 != y2) // 如果只有一列，right col 已经遍历了列
                for(int i = x2-1;i > x1;--i) ret.push_back(matrix[i][y1]);  // left col
            ++x1,++y1,--x2,--y2;
        }
        return ret;
    }
};
