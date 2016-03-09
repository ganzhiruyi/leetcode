class Solution {
public:
    int min3(int a,int b,int c){ return min(min(a,b),c); }
    int minDistance(string word1, string word2) {
        int l1 = word1.length(),l2 = word2.length();
        int f[l1+1][l2+1];
        for(int i = 0;i <= l1;++i) f[i][0] = i;        
        for(int j = 0;j <= l2;++j) f[0][j] = j;
        for(int i = 1;i <= l1;++i)
            for(int j = 1;j <= l2;++j){
                if(word1[i-1] == word2[j-1])
                    f[i][j] = f[i-1][j-1];
                else
                    f[i][j] = min3(f[i-1][j],f[i][j-1],f[i-1][j-1]) + 1;
            }
        return f[l1][l2];        
    }
};
