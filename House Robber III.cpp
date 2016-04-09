class Solution {
public:
    typedef pair<int,int> pii;
    struct IndexNode{
        IndexNode *left,*right;
        int val,idx;
        IndexNode(int val,int idx):val(val),idx(idx),left(NULL),right(NULL){}
    };
    vector<pii> f;
    int cnt;
    IndexNode* build(TreeNode *rt){
        IndexNode *x = new IndexNode(rt->val,cnt++);
        if(rt->left)
            x->left = build(rt->left);
        if(rt->right)
            x->right = build(rt->right);
        return x;
    }
    int dfs(IndexNode *rt,int isRob){
        if(rt == NULL) return 0;
        int idx = rt->idx;
        if(!isRob && f[idx].first != -1)
            return f[idx].first;
        else if(isRob && f[idx].second != -1)
            return f[idx].second;
        int ret = isRob ? rt->val : 0;
        if(isRob){
            ret += dfs(rt->left,0);
            ret += dfs(rt->right,0);
        }
        else{
            ret += max(dfs(rt->left,1),dfs(rt->left,0));
            ret += max(dfs(rt->right,1),dfs(rt->right,0));            
        }
        if(!isRob)
            f[idx].first = ret;
        else f[idx].second = ret;
        return ret;
    }
    int rob(TreeNode* root) {
        if(!root) return 0;
        cnt = 0;
        IndexNode *newRt = build(root);
        printf("cnt:%d\n", cnt);
        f = vector<pii>(cnt,make_pair(-1,-1));
        return max(dfs(newRt,1),dfs(newRt,0));
    }
};
