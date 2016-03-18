class Solution {
public:
    int charType(char ch){
        if(!('a'<=ch && ch<='z') && !('A'<=ch && ch<='Z') && 
           !('0'<=ch && ch <= '9'))
            return -1;
        if('a'<=ch && ch<='z') return ch-'a';
        else if('A'<=ch && ch<='Z') return ch-'A';
        return ch-'0'+26;
    }
    bool isPalindrome(string s) {
        string::iterator l = s.begin(),r = s.end();
        if(l == r) return true; // empty string
        --r;
        int idxL,idxR;
        while(l < r){
            idxL = charType(*l),idxR = charType(*r);
            if(idxL == -1) ++l;
            if(idxR == -1) --r;
            if(idxL == idxR && idxL != -1) ++l,--r;
            if(idxL != idxR && idxL != -1 && idxR != -1) return false;
        }
        return true;
    }
};
