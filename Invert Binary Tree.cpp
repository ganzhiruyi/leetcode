class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        TreeNode *ls = invertTree(root->left);
        TreeNode *rs = invertTree(root->right);
        root->left = rs;
        root->right = ls;
        return root;
    }
};
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *p;
        while(!q.empty()){
            p = q.front();
            q.pop();
            swap(p->left,p->right);
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }
        return root;
    }
};
