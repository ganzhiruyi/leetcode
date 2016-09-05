class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[26];
        memset(cnt,0,sizeof(cnt));
        for(int i = 0;i < magazine.size();++i)
            ++cnt[magazine[i]-'a'];
        for(int i = 0;i < ransomNote.size();++i)
            if(--cnt[ransomNote[i]-'a'] < 0) return false;
        return true;
    }
};
