#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int N;
    vector<vector<string> > ans;
    bool check(int x,int y,vector<int> &col){
        for(int i = 0;i < x;++i)
            if(col[i] == y || abs(y-col[i])==x-i) return false;
        return true;
    }
    int dfs(int i, vector<int> &col){
        if(i == N){
            vector<string> v;
            for(int j = 0;j < N;++j){
                string s(N,'.');
                s[col[j]] = 'Q';
                v.push_back(s);
            }
            ans.push_back(v);
            return 1;
        }
        int ret = 0;
        for(int j = 0;j < N;++j){
            if(check(i,j,col)){
                col[i] = j;
                ret += dfs(i+1,col);
            }
        }
        return ret;
    }
    vector<vector<string> > solveNQueens(int n) {
        N = n;
        ans.clear();
        vector<int> col(n,0);
        dfs(0,col);
        return ans;
    }
};
int main(){
    int n;
    Solution sol;
    while(cin >> n){
        vector<vector<string> > ans = sol.solveNQueens(n);
        for(int i = 0;i < ans.size();++i){
            for(int j = 0;j < ans[i].size();++j){
                cout << ans[i][j] << endl; 
            }
            cout << "************" << endl;
        }
    }
    return 0;
}
