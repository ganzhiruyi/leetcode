class Solution {
public:
    string convertToTitle(int n) {
        string ret = "";
        while(n){
            ret += char((n-1)%26+'A');
            n = (n-1)/26; // 这里要n-1,1对应A
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
