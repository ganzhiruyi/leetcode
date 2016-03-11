class Solution {
public:
    vector<vector<int>> ans; 
    void dfs(int n,int k,int st,vector<int> &vis){
        if(k == 0){
            vector<int> t;
            for(int i = 0;i < n;++i)
                if(vis[i]) t.push_back(i+1);
            ans.push_back(t); 
            return;
        }
        for(int i = st;i < n;++i){
            if(!vis[i]){
                vis[i] = 1;
                dfs(n,k-1,i+1,vis);
                vis[i] = 0;
            }
        }
    }
    vector<vector<int>> combine(int n, int k) { 
        ans.clear();
        vector<int> v(n,0);
        dfs(n,k,0,v);
        return ans;
    }
};
