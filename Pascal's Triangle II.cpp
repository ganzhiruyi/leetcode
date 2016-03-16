class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return vector<int>(1,1);
        vector<int> ret(rowIndex+1,1);
        for(int i = 1;i <= rowIndex;++i){
            for(int j = 1;j < i;++j){
                int tmp = ret[i]+ret[j]; //用第i行的最后一个存储
                ret[i] = ret[j];
                ret[j] = tmp;
            }
        }
        ret[rowIndex] = 1;
        return ret;
    }
};
