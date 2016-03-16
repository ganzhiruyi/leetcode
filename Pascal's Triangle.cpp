class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        if(!numRows) return ret;
        ret.push_back(vector<int>(1,1));
        for(int i = 1;i < numRows;++i){
            ret.push_back(vector<int>(i+1,1));
            for(int j = 1;j < i;++j)
                ret[i][j] = (ret[i-1][j-1]+ret[i-1][j]);
        }
        return ret;
    }
};
