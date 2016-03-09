class Solution {
public:
    string addBinary(string a, string b) {
        int la = a.length(),lb = b.length();
        int tmp,up = 0,i = la-1,j = lb-1;
        string ret = "";
        while(i >= 0 && j >= 0){
            tmp = (a[i]-'0') + (b[j]-'0') + up;
            ret += (tmp%2+'0');
            up = tmp/2;
            --i,--j;
        }
        while(i >= 0){
            tmp = (a[i]-'0') + up;
            ret += (tmp%2+'0');
            up = tmp/2;
            --i;
        }
        while(j >= 0){
            tmp = (b[j]-'0') + up;
            ret += (tmp%2+'0');
            up = tmp/2;
            --j;
        }
        if(up) ret += (up+'0');
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
