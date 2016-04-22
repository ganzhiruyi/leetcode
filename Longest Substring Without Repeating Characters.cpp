class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //思路：从头到尾扫一遍，维护一个[i,j]区间，该区间保证没有重复的字符，
        //在每个位先把该字符的总数加1，检查当前的字符是否超过1，超过则前移指针i,
        //同时更新前移过程中字符总数直到当前字符总数为1。记一个最大值每次比较。
        int i = 0,j = 0,len = s.length();
        if(len == 0) return 0;
        map<char,int> M;
        int maxLen = 0;
        for(;j<len;j++){
            M[s[j]]++;
            while(M[s[j]] > 1){
                M[s[i]]--;
                i++;
            }
            maxLen = max(maxLen,j-i+1);
        }
        return maxLen;
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int alpha[1024],ret = 0;
        memset(alpha,0,sizeof(alpha));
        int start = 0;
        for(int i = 0;i < n;++i){
            while(start < i && alpha[s[i]]){
                alpha[s[start]] = 0;
                ++start;
            }
            alpha[s[i]] = 1;
            ret = max(ret,i-start+1);
        }
        return ret;
    }
};
