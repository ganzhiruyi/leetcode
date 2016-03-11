int dir[][2] = {-1,0,0,1,1,0,0,-1};
class Solution {
public:
    int n,m;
    string w;
    bool dfs(int x,int y,int cnt,vector<vector<char>>& board){
        if(cnt == w.length()) return true;
        for(int d = 0;d < 4;++d){
            int tx = x+dir[d][0],ty = y+dir[d][1];
            if(0<=tx && tx<n && 0<=ty && ty<m && 
               board[tx][ty] != '*' && w[cnt]==board[tx][ty]){
                char letter = board[tx][ty];
                board[tx][ty] = '*';
                if(dfs(tx,ty,cnt+1,board)) return true;
                board[tx][ty] = letter;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(),m = board[0].size();
        w = word;
        for(int i = 0;i < n;++i)
            for(int j = 0;j < m;++j)
                if(board[i][j] == word[0]){
                    char letter = board[i][j];
                    board[i][j] = '*';
                    if(dfs(i,j,1,board)) return true;
                    board[i][j] = letter;
                }
        return false;
    }
};
