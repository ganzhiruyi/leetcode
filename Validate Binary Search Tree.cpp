/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //注意二叉查找的性质是左子树的所有节点都比根节点小，右子树的所有节点都比根节点大
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return traverse(root,INT_MIN,INT_MAX);
        
    }
    bool traverse(TreeNode *rt,int l,int r){
        if(rt == NULL) return true;
        if(l > r) return false;
        bool res = true;
        TreeNode *ls = rt->left,*rs = rt->right;
        if(l >= rt->val || rt->val >= r) return false; 
        res = res && traverse(rt->left,l,rt->val);
        res = res && traverse(rt->right,rt->val,r);
        return res;
    }
    
};
