class Solution {
public:
    string int2str(int x){
        if(!x) return "0";
        string ret = "";
        while(x){
            ret += (x%10+'0');
            x /= 10;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    string getHint(string secret, string guess) {
        int cntS[10],cntG[10],bull = 0;
        memset(cntS,0,sizeof(cntS));
        memset(cntG,0,sizeof(cntG));
        for(int i = 0;i < secret.size();++i){
            if(secret[i]==guess[i]) ++bull;
            else{
                ++cntS[secret[i]-'0'];
                ++cntG[guess[i]-'0'];
            }
        }
        int cow = 0;
        for(int i = 0;i < 10;++i) cow += min(cntS[i],cntG[i]);
        string ret = int2str(bull)+"A"+int2str(cow)+"B";
        return ret;
    }
};
