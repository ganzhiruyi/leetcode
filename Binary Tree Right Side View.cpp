/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> view;
    int cnt; // 表示当前从顶到底view已经有几个元素了
    void dfs(TreeNode *root,int depth){
        if(!root) return;
        if(cnt == depth){
            ++cnt;
            view.push_back(root->val);
        }
        dfs(root->right,depth+1);
        dfs(root->left,depth+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return vector<int>();
        cnt = 0;
        view.clear();
        dfs(root,0);
        return view;
    }
};
