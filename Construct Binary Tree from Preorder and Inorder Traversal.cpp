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
    typedef vector<int>::iterator iterator;
    TreeNode *build(iterator &pl,iterator &pr,iterator &il,iterator &ir){
        if(pl >= pr) return NULL;
        int rootval = *pl;
        iterator pivot = il;
        while(pivot < ir && *pivot != rootval) ++pivot;
        TreeNode *rt = new TreeNode(rootval);
        int len = pivot-il;//left tree length
        iterator tmp = pl+len+1;
        rt->left = build(pl,tmp,il,pivot);
        rt->right = build(tmp,pr,++pivot,ir);
        return rt;        
    }
    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return build(preorder.begin(), preorder.end(),inorder.begin(), inorder.end());
    }
};
