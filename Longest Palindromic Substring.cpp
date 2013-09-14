class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() 
        //dp[i][j] = dp[i+1][j-1]&&s[i]==s[j]
        int len = s.length();
        if(len == 0) return s;
        int l = 0,maxlen = 1;
        bool dp[1010][1010];
        memset(dp,false,sizeof(dp));
        for(int i = 0;i < len;i++){
            dp[i+1][i] = true;
            dp[i][i] = true;
        }
        for(int k = 2;k <= len;k++){
            for(int i = 0;i < len;i++){
                int j = i+k-1;
                if(j >= len) break;
                if(s[i] == s[j] && dp[i+1][j-1]){
                    if(maxlen < k){
                        maxlen = k;
                        l = i;
                    }
                    dp[i][j] = true;
                }
            }
        }
        return s.substr(l,maxlen);
    }
};
