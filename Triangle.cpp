class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(!n) return 0;
        int tmp,ret;
        vector<int> f(n+1);
        f[0] = triangle[0][0];
        for(int i = 1;i < n;++i){
            for(int j = 0;j <= i;j++){
                if(!j) tmp = f[0]+triangle[i][j];
                else if(j == i) tmp = f[i+1]+triangle[i][j];
                else tmp = min(f[i+1],f[j])+triangle[i][j];
                f[i+1] = f[j];
                f[j] = tmp; 
            }
        }
        ret = f[0];
        for(int i = 1;i < n;++i) ret = min(ret,f[i]);
        return ret;
    }
};
