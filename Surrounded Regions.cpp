class Solution {
public:
    vector<int> fa;
    vector<int> surround;
    int find(int x){
        return fa[x]==x ? x : fa[x] = find(fa[x]);
    }
    void Union(int x,int y){
        int fx = find(x),fy = find(y);
        if(fy != fx){
            fa[fx] = fy;
            // 这一个判断不能少，如果子分枝fx没有被包围，父分支一定不会被包围
            if(surround[fx] == 0) surround[fy] = 0;
        }
    }
    void solve(vector<vector<char>>& board) {
         int n = board.size();
         if(!n) return;
         int m = board[0].size();
         fa = vector<int>(n*m);
         surround = vector<int>(n*m,1);
         for(int i = 0;i < n*m;++i) fa[i] = i;
         int now,right,down;
         for(int i = 0;i < n;++i)
             for(int j = 0;j < m;++j){
                 if(board[i][j] == 'X') continue;
                 now = i*m+j;
                 if(i+1 < n && board[i+1][j] == 'O'){
                     down = now + m;
                     Union(now,down);
                 }
                 if(j+1 < m && board[i][j+1] == 'O'){
                     right = now + 1;
                     Union(now,right);
                 }
                 if(!i||i==n-1||!j||j==m-1){
                     // 如果(i,j)在边界上，则(i,j)所在的分支一定不会被包围
                     int x = find(now);
                     surround[x] = 0; 
                 }
             }
        for(int i = 0;i < n;++i)
            for(int j = 0;j < m;++j){
                if(board[i][j] == 'O'){
                    int x = find(i*m+j);
                    if(surround[x]) board[i][j] = 'X';
                }
            }
    }
};
