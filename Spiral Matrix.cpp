class Solution {
public:
    // static int dir[][2] = {0,1,1,0,0,-1,-1,0};
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> ret;
        if(matrix.size() == 0) return ret;
        int dir[][2] = {0,1,1,0,0,-1,-1,0};
        int d = 0,m = matrix.size(),n = matrix[0].size();
        int x = 0, y = 0;
        ret.push_back(matrix[x][y]);
        --n;
        while(n){
            if(d == 3) --n;
            for(int i = 0;i < n;++i){
                x += dir[d][0], y += dir[d][1];
                ret.push_back(matrix[x][y]);
            }
            d = (d+1)%4;
        }
        return ret;
    }
};
