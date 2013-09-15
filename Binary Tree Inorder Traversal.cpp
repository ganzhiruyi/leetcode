/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode *rt,vector<int> &a){
        if(rt == NULL) return;
        traverse(rt->left,a);
        a.push_back(rt->val);
        traverse(rt->right,a);
    }
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> inorder;
        inorder.clear();
        traverse(root,inorder);
        return inorder;
    }
};
