class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length(),ret = 0;
        int i;
        for(i = n-1;i >= 0 && s[i] == ' ';--i);
        for(;i >= 0 && s[i] != ' ';--i) ++ret;
        return ret;
    }
};
