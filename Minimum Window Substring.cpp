class Solution {
public:
    int idx(char ch){
        if('A'<=ch && ch <= 'Z') return ch-'A';
        return ch-'a'+26;
    }
    string minWindow(string s, string t) {
        int i = 0,j = 0,n = s.length(),m = t.length();
        if(!n || !m) return "";
        int cnt[52],cur[52];
        memset(cnt,0,sizeof(cnt));
        memset(cur,0,sizeof(cur));
        for(int k = 0;k < m;k++) ++cnt[idx(t[k])];
        bool start = false;
        int all = 0,ans = n+1,l = -1;
        while(j < n){
            if(cnt[idx(s[j])]){
                if(!start){
                    i = j;
                    start = true;
                }
                if(cur[idx(s[j])] < cnt[idx(s[j])]){
                    ++all;
                }
                ++cur[idx(s[j])];
                if(all == m){
                    if(ans > j-i+1){
                        l = i;
                        ans = j-i+1;
                    }
                    int ti = i;
                    // 将i前移
                    while(i <= j && (cnt[idx(s[i])] < 0 || 
                                     cur[idx(s[i])] > cnt[idx(s[i])])){
                        --cur[idx(s[i])];
                        ++i;
                    }
                    // 此时满足局部恰好最少的字母且all==m
                    if(i > ti){
                        if(ans > j-i+1){
                            l = i;
                            ans = j-i+1;
                        }
                    }
                    if(cnt[idx(s[i])]){
                        --cur[idx(s[i])];
                        ++i;
                        --all;
                    }
                }
            }
            ++j;
        }
        if(l == -1) return "";
        return s.substr(l,ans);
    }
};
