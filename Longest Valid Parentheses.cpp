class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int matched[n+1],st[n+1],top = 0;
        for(int i = 0;i < n;i++){
            if(s[i] == '('){
                st[top++] = i;
                matched[i] = -1;
            }
            else{
                matched[i] = -1;
                if(top){
                    --top;
                    matched[st[top]] = i;
                    matched[i] = st[top]; 
                }
            }
        }
        int ret = 0,cnt = 0;
        for(int i = 0;i < n;i++){
            if(matched[i] >= 0) ++cnt;
            else{
                ret = max(ret,cnt);
                cnt = 0;
            }
        }
        ret = max(ret,cnt);
        return ret;
    }
};
