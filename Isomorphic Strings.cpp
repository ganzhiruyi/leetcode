class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mp[256];
        memset(mp,-1,sizeof(mp));
        for(int i = 0;i < s.length();++i){
            if(s[i] != t[i]){
                if(mp[s[i]] == -1){
                    int val = t[i];
                    bool has = false;
                    // 判断s中之前是否已有匹配过这个val，避免两个词匹配同一个
                    for(int i = 0;i < 256;++i)
                        if(mp[i] == val){
                            has = true;
                            break;
                        }
                    if(has) return false;
                    mp[s[i]] = val;
                }
                else if(mp[s[i]] != t[i]) return false;
            }
            else{
                // 有些位置虽然一样，但是之前已经s已经匹配了另一个字符，所以要判断
                if(mp[s[i]] != -1 && mp[s[i]] != s[i]) return false; 
                mp[s[i]] = s[i];
            }
        }
        return true;
    }
};
