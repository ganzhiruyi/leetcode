#include <bits/stdc++.h>
using namespace std;
// time:O(n^2),space:O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {
        // dp[i][j]表示s[i,j]范围内的最长的回文子串
        //dp[i][j] = dp[i+1][j-1]&&s[i]==s[j]
        int len = s.length();
        if(len == 0) return s;
        int l = 0,maxlen = 1;
        bool dp[1010][1010];
        memset(dp,0,sizeof(dp));
        // 长度为1的子串
        for(int i = 0;i < len;i++)
            dp[i][i] = true;
        // 长度为2的子串,因为dp[i+1][j-1]对于长度为2可能造成i+1>j-1,所以特判
        for(int i = 1;i < len;++i)
            if(s[i] == s[i-1]){
                dp[i-1][i] = true;
                maxlen = 2;
                l = i-1;
            }
        for(int k = 3;k <= len;k++){
            for(int i = 0;i < len-k+1;i++){
                int j = i+k-1;
                if(s[i] == s[j] && dp[i+1][j-1]){
                    if(maxlen < k){
                        maxlen = k;
                        l = i;
                    }
                    dp[i][j] = true;
                }
            }
        }
        return s.substr(l,maxlen);
    }
};
// time:O(n^2),space:O(1)
class Solution {
public:
    string longestPalindrome(string s) {
        int low,high,l = 0,maxlen = 1;
        int n = s.length();
        for(int i = 1;i < n;++i){
            // 以i-1,i为中心构建偶数长度的回文串
            low = i-1,high = i;
            while(low>=0 && high<n && s[low]==s[high]){
                if(high-low+1 > maxlen){
                    maxlen = high-low+1;
                    l = low;
                }
                --low,++high;
            }
            // 以i为中心构建奇数长度的回文串
            low = i-1,high = i+1;
            while(low>=0 && high<n && s[low]==s[high]){
                if(high-low+1 > maxlen){
                    maxlen = high-low+1;
                    l = low;
                }
                --low,++high;
            }
        }
        return s.substr(l,maxlen);
    }
};
// time:O(n),space:O(n)
class Solution {
public:
    string preProcess(string &s){
        /** 预处理
        1.将s都添加#,abba变成#a#b#b#a#，这样使得回文串都变成奇数个
        2.在两头添加两个不相等的特殊字符,所以在1生成的字符串头部添加一个^,
        在尾部添加一个$.
        **/
        string ret = "^";
        for(int i = 0;i < s.length();++i)
            ret = ret+"#"+s[i];
        ret += "#$";
        // cout << ret << endl;
        return ret;
    }
    string longestPalindrome(string s) {
        if(s.length() == 0) return s; 
        string ps = preProcess(s);
        int n = ps.length();
        /** 
        p[i]表示以ps[i]为中心的回文串向左/右能扩展的长度
        C表示在i之前获得的右边界最远的回文串的中心点下标
        R表示在i之前获得的最远右边界
        center表示最长回文子串的中心点
        maxp表示最长回文子串的p[center]长度
        **/
        int center,maxp = 0;
        int p[n],C = 0,R = 0;
        memset(p,0,sizeof(p)); 
        for(int i = 1;i < n-1;++i){
            p[i] = R < i ? 0 : min(p[2*C-i],R-i);
            while(ps[i+1+p[i]] == ps[i-p[i]-1]) ++p[i]; // 继续匹配
            if(R < i+p[i]){ // 更新右边界mx及对应的中心点id
                C = i;
                R = i+p[i];
            }
            if(p[i] > maxp){ // p[i]-1就对应原来最大的回文串长度
                center = i;
                maxp = p[i];
            }
        }
        // printf("center:%d,maxp:%d\n", center,maxp);
        // 利用center还原原来的回文串
        int l = (center-maxp)/2;
        return s.substr(l,maxp);
    }
};
int main(){
    Solution sol;
    string s;
    while(cin >> s){
        cout << sol.longestPalindrome(s) << endl;
    }
    return 0;
}
