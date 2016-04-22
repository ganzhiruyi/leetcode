class Solution {
public:
    bool wordBreak1(string s, unordered_set<string>& wordDict) {
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
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.length();
        // 要先判断是否能分割，能的话再进行记录,否则TLE
        if(!wordBreak1(s,wordDict)) 
            return vector<string>();
        vector<int> f(n,0);
        vector<vector<string>> ans(n,vector<string>());
        if(wordDict.count(s.substr(0,1))){
            f[0] = 1;
            ans[0].push_back(s.substr(0,1));
        }
        string tmp;
        for(int i = 1;i < n;++i){
            for(int j = 0;j < i;++j){
                tmp = s.substr(j+1,i-j);
                if(f[j] && wordDict.count(tmp)){
                    f[i] = 1;
                    for(int k = 0;k < ans[j].size();++k)
                        ans[i].push_back(ans[j][k]+" "+tmp);
                }
            }
            tmp = s.substr(0,i+1);
            if(wordDict.count(tmp)){
                ans[i].push_back(tmp);
                f[i] = 1;
            }
        }
        return ans[n-1];
    }
};
