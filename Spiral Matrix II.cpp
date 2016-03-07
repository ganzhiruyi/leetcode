class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret;
        if(!n) return ret;
        for(int i = 0;i < n;++i) ret.push_back(vector<int>(n));
        int x1 = 0,y1 = 0,x2 = n-1,y2 = n-1,num = 1;
        while(x1 <= x2 && y1 <= y2){
            for(int i = y1;i <= y2;++i) ret[x1][i] = num++;
            for(int i = x1+1;i <= x2;++i) ret[i][y2] = num++;
            if(x1 != x2)
                for(int i = y2-1;i >= y1;--i) ret[x2][i] = num++;
            if(y1 != y2)
                for(int i = x2-1;i > x1;--i) ret[i][y1] = num++;
            ++x1,++y1,--x2,--y2;  
        }
        return ret;
    }
};
