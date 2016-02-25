class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        if(n != 9) return false;
        n = board[0].size();
        if(n != 9) return false;
        int digit[10];
        for(int i = 0;i < n;++i){
            memset(digit,0,sizeof(digit));
            for(int j = 0;j < n;++j){
                if(board[i][j] == '.') continue;
                int num = board[i][j]-'0';
                if(digit[num]) return false;
                digit[num] = 1;
            }
        }
        for(int i = 0;i < n;++i){
            memset(digit,0,sizeof(digit));
            for(int j = 0;j < n;++j){
                if(board[j][i] == '.') continue;
                int num = board[j][i]-'0';
                if(digit[num]) return false;
                digit[num] = 1;
            }
        }
        int add[9] = {0,1,2,9,10,11,18,19,20};
        int leftup[9] = {0,3,6,27,30,33,54,57,60};
        for(int k = 0;k < n;++k){
            memset(digit,0,sizeof(digit));
            for(int p = 0;p < n;p++){
                int tmp = leftup[k]+add[p];
                int i = tmp/n,j = tmp%n;
                if(board[i][j] == '.') continue;
                int num = board[i][j]-'0';
                if(digit[num]) return false;
                digit[num] = 1;
            }
        }
        return true;
    }
};
