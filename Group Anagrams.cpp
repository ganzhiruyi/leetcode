#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    struct Node{
        vector<int> count;
        int idx;
    };
    static bool cmp(const Node &a, const Node &b){
        return a.count < b.count;
    }

    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<Node> cnt;
        for(int i = 0;i < strs.size();++i){
            vector<int> v(26,0);
            for(int j = 0;j < strs[i].length();++j){
                ++v[strs[i][j]-'a'];
            }
            Node nd;
            nd.count = v;
            nd.idx = i;
            cnt.push_back(nd);
        }
        sort(cnt.begin(),cnt.end(),cmp);
        vector<vector<string> > ans;
        int i = 0;
        for(;i < cnt.size();){
            vector<string> v;
            v.push_back(strs[cnt[i].idx]);
            int j = i+1;
            for(;j < cnt.size();++j){
                bool isok = true;
                for(int k = 0;k < 26;++k){
                    if(cnt[i].count[k] != cnt[j].count[k]){
                        isok = false;
                        break;
                    }
                }
                if(isok) v.push_back(strs[cnt[j].idx]);
                else break;
            }
            sort(v.begin(),v.end());
            ans.push_back(v);
            if(j < cnt.size()) i = j;
            else break;
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        unordered_set<string> hash;
        sort(strs.begin(), strs.end());
        unordered_map<string,int> mp;
        vector<vector<string> > ret;
        int cnt = 0;
        for(int i = 0;i < strs.size();++i){
            string ts = strs[i];
            sort(ts.begin(), ts.end());
            if(hash.find(ts)==hash.end()){
                mp[ts] = cnt++;
                hash.insert(ts);
                ret.push_back({strs[i]});
            }
            else{
                ret[mp[ts]].push_back(strs[i]);
            }
        }
        return ret;
    }
};
int main(){
    vector<string> str;
    string s;
    while(cin >> s){
        str.push_back(s);
    }
    Solution sol;
    vector<vector<string> > ans = sol.groupAnagrams(str);
    for(int i = 0;i < ans.size();++i){
        for(int j = 0;j < ans[i].size();++j){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
