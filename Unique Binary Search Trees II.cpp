/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //递归搜索答案，先后搜索左右子树，这里用[l,r]来标示l~r构成的子树
class Solution {
public:
    vector<TreeNode *> generate(int l,int r){
        vector<TreeNode *> ret;
        if(r < l){
            ret.push_back(NULL);
            return ret;
        }
        for(int rooval = l;rooval <= r;rooval++){
            vector<TreeNode *> vecl = generate(l,rooval-1);
            vector<TreeNode *> vecr = generate(rooval+1,r);
            for(int i = 0;i < vecl.size();i++){
                for(int j = 0;j < vecr.size();j++){
                    TreeNode *root = new TreeNode(rooval);
                    root->left = vecl[i];
                    root->right = vecr[j];
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return generate(1,n);
    }
};
