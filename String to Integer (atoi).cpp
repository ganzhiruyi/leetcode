class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //注意溢出
        int len = strlen(str);
        int flag = 0,ans = 0;
        for(int i = 0;i < len;i++){
            if(str[i] == ' ') continue;
            while(str[i] == '-' || str[i] == '+' || ('0'<=str[i]&&str[i]<='9')){
                if(flag && (str[i] == '-'||str[i] == '+')) break;
                if('0'<=str[i]&&str[i]<='9'){
                    if(ans > INT_MAX/10){
                        if(flag <= 1) return INT_MAX;
                        if(flag == 2) return INT_MIN;    
                    }
                    ans = ans*10+(str[i]-'0');
                }
                if(flag <= 1 && ans < 0) return INT_MAX;
                if(flag == 2 && ans < 0) return INT_MIN;
                else if(str[i] == '-') flag = 2;
                else if(str[i] == '+') flag = 1; 
                i++;
                if(i == len) break;
            }
            break;
        }
        if(flag == 2) ans = -ans;
        return ans;
    }
};
