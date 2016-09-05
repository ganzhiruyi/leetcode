class Solution {
public:
    char findTheDifference(string s, string t) {
        int hash_s[26],hash_t[26];
        memset(hash_s,0,sizeof(hash_s));
        memset(hash_t,0,sizeof(hash_t));
        for(int i = 0;i < s.length();++i) hash_s[s[i]-'a'] += 1;
        for(int i = 0;i < t.length();++i) hash_t[t[i]-'a'] += 1;
        for(int i = 0;i < 26;++i)
            if(hash_s[i] != hash_t[i]) return i+'a';
        return NULL;
    }
};
