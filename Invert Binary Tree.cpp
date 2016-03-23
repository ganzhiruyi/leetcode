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
