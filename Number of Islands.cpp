class Solution {
public:
    vector<int> fa;
    vector<int> rank;
    int find(int x){
        return fa[x]==x ? x : fa[x] = find(fa[x]);
    }
    void Union(int x,int y){
        int fx = find(x),fy = find(y);
        if(fx != fy){
            if(rank[fx] > rank[fy]) fa[fy] = fx;
            else{
                if(rank[fx] == rank[fy]) ++rank[fy];
                fa[fx] = fy;
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(!n) return 0;
        int m = grid[0].size();
        fa = vector<int>(n*m);
        rank = vector<int>(n*m);
        for(int i = 0;i < n*m;++i){
            fa[i] = i;
            rank[i] = 0;
        }
        int now,right,down;
        for(int i = 0;i < n;++i)
            for(int j = 0;j < m;++j){
                if(grid[i][j] == '0') continue;
                now = i*m+j;
                if(j+1 < m && grid[i][j+1] == '1'){
                    right = now + 1;
                    Union(now,right);
                }
                if(i+1 < n && grid[i+1][j] == '1'){
                    down = now+m;
                    Union(now,down);
                }
            }
        int ans = 0;
        for(int i = 0;i < n;++i)
            for(int j = 0;j < m;++j)
                if(grid[i][j] == '1' && fa[i*m+j] == i*m+j)
                    ++ans;
        return ans;        
    }
};
