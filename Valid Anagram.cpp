class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int cnt[26];
        memset(cnt,0,sizeof(cnt));
        for(int i = 0;i < s.length();++i) ++cnt[s[i]-'a'];
        for(int i = 0;i < t.length();++i)
            if(--cnt[t[i]-'a'] < 0) return false;
        for(int i = 0;i < 26;++i)
            if(cnt[i]) return false;
        return true;
    }
};
