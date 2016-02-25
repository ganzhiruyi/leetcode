class Solution {
public:
    string int2str(int n){
        string ret = "";
        while(n){
            ret += (n%10+'0');
            n /= 10;
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
    string countAndSay(int n) {
        string nums = "1";
        while(--n){
            int i = 0;
            int st,cnt;
            char curChar = nums[i];
            string tmp = "";
            while(i < nums.length()){
                st = i;
                while(i < nums.length() && curChar==nums[i]) ++i;
                cnt = i-st;
                tmp += int2str(cnt);
                tmp += curChar;
                if(i < nums.length()) curChar = nums[i];
                st = i;
            }
            nums = tmp;
        }
        return nums;        
    }
};
