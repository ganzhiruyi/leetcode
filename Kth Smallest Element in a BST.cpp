class Solution {
public:
    int cnt = 0;
    void dfs(TreeNode *rt,int k){
        if(!rt) return;
        if(rt->left) dfs(rt->left,k);
        if(++cnt==k){
            ans = k;
            return;
        }
        if(rt->right) dfs(rt->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        cnt = 0;
        dfs(root,k);
        return ans;
    }
};
