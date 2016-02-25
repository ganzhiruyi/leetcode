class Solution {
public:
    struct Point{
        int x,y;
        Point(int x,int y):x(x),y(y){}
    };
    vector<Point> unfill;
    bool check(int x,int y,char c,vector<vector<char>>& board){
        // 这里不需要考虑i取到x或者y，因为这时候点(x,y)还是未填的状态'.'
        for(int i = 0;i < 9;++i)
            if(board[i][y]==c || board[x][i]==c) return false;
        int lx = x/3*3, ly = y/3*3;
        for(int i = lx;i < lx+3;++i)
            for(int j = ly;j < ly+3;++j)
                if(board[i][j] == c) return false;
        return true;
    }
    bool dfs(int idx,vector<vector<char>>& board){
        if(idx == unfill.size()) return true;
        Point p = unfill[idx];
        for(int i = 1;i <= 9;++i)
            if(check(p.x,p.y,i+'0',board)){
                board[p.x][p.y] = i+'0';
                if(dfs(idx+1,board)) return true;
                board[p.x][p.y] = '.'; 
            }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        unfill.clear();
        for(int i = 0;i < 9;i++)
            for(int j = 0;j < 9;j++)
                if(board[i][j] == '.') unfill.push_back(Point(i,j));
        dfs(0,board);
    }
};
