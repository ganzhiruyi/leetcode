class Solution {
public:
    bool wordPattern(string pattern, string str) {
        string mp[26];
        for(int i = 0;i < 26;++i) mp[i] = "";
        int j = 0;
        for(int i = 0;i < pattern.size();++i){
            string s = "";
            while(j < str.length() && str[j] != ' ') s += str[j++];
            ++j; // 跳过空格
            if(mp[pattern[i]-'a'] == ""){
                for(int i = 0;i < 26;++i)
                    if(mp[i] == s) return false;  //如何已经存在这样的映射
                mp[pattern[i]-'a'] = s;
            }
            else if(mp[pattern[i]-'a'] != s) return false;
        }
        if(j < str.length()) return false; // 如果word的个数比模式个数多
        return true;
    }
};
