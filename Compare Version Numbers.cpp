class Solution {
public:
    vector<int> solve(string s){
        int cur = 0;
        vector<int> ret;
        for(int i = 0;i < s.length();++i){
            if(s[i] == '.'){
                ret.push_back(cur);
                cur = 0;
            }
            else cur = cur*10+(s[i]-'0');
        }
        if(cur) ret.push_back(cur);
        return ret;
    }
    int compareVersion(string version1, string version2) {
        vector<int> p1 = solve(version1),p2 = solve(version2);
        int i = 0;
        while(i<p1.size() && i<p2.size()){
            if(p1[i] != p2[i]) return p1[i] < p2[i] ? -1 : 1;
            ++i;
        }
        while(i < p1.size() && p1[i] == 0) ++i;
        if(i < p1.size()) return 1;
        while(i < p2.size() && p2[i] == 0) ++i;
        if(i < p2.size()) return -1;
        return 0;
    }
};
