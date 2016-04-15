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
    int countNodes(TreeNode* root){
        if(!root) return 0;
        return countNodes(root,-1,-1);
    }
    int countNodes(TreeNode* root,int lh,int rh) {
        if(lh == -1){ // 之前没有计算过最左的高度
            lh = 0;
            for(TreeNode *p = root;p;p = p->left) ++lh;
        }
        if(rh == -1){ // 之前没计算过最右的高度
            rh = 0;
            for(TreeNode *p = root;p;p = p->right) ++rh;
        }
        if(lh == rh) return (1<<lh)-1;
        return 1+countNodes(root->left,lh-1,-1)+countNodes(root->right,-1,rh-1);
    }
};
