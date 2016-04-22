class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.length();
        // f[i]表示以s[i]为结尾的子串是否能够拆分
        vector<int> f(n+1,0);
        f[0] = wordDict.count(s.substr(0,1));
        for(int i = 1;i < n;++i){
            for(int j = 0;j < i;++j){
                if(f[j] && wordDict.count(s.substr(j+1,i-j)))
                    f[i] = 1;
            }
            if(wordDict.count(s.substr(0,i+1))) f[i] = 1;
        }
        return f[n-1];
    }
};
