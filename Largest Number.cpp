#include <bits/stdc++.h>
using namespace std;
int k = 0;
static bool cmp(const string &a,const string &b){
    ++k;
    cout<< k <<" : " << a << "," << b << endl;
    int i = 0,j = 0,la = a.length(),lb = b.length();
    while(i<la && j<lb){
        if(a[i] > b[j]) return true;
        else if(a[i] < b[j]) return false;
        ++i,++j;
    }
    if(i < la)
        return cmp(a.substr(i,la-i),b);
    if(j < lb)
        return cmp(a,b.substr(j,lb-j));
    return true;
}
class Solution {
public:
    static bool cmp1(const string &a,const string &b){
        return a+b > b+a;
    }
    string largestNumber(vector<int>& nums) {
        if(nums.size() == 0) return "";
        vector<string> strs(nums.size());
        for(int i = 0;i < nums.size();++i){
            stringstream ss;
            ss << nums[i];
            ss >> strs[i];
        }
        sort(strs.begin(),strs.end(),cmp1);
        string ret = "";
        for(int i = 0;i < strs.size();++i)
            ret += strs[i];
        int k = 0,n = ret.length();
        while(k < n && ret[k] == '0') ++k;
        return k == n ? "0":ret.substr(k,n-k);
    }
};
int main(){
    Solution sol;
    int n;
    vector<int> v;
    while(cin >> n){
        v.push_back(n);
    }
    cout << v.size() << endl;
    cout << sol.largestNumber(v) << endl;
    return 0;
}
