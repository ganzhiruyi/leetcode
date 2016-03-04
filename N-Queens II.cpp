class Solution {
public:
    int N;
    bool check(int x,int y,vector<int> &col){
        for(int i = 0;i < x;++i)
            if(col[i] == y || abs(y-col[i])==x-i) return false;
        return true;
    }
    int dfs(int i, vector<int> &col){
        if(i == N) return 1;
        int ret = 0;
        for(int j = 0;j < N;++j){
            if(check(i,j,col)){
                col[i] = j;
                ret += dfs(i+1,col);
            }
        }
        return ret;
    }
    int totalNQueens(int n) {
        N = n;
        vector<int> col(n,0);
        return dfs(0,col);
    }
};
