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
    struct LNode{
        TreeNode *rt;
        int level;
        LNode(TreeNode *rt,int level) : level(level),rt(rt){}
    };
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<LNode*> q;
        vector<vector<int>> ret;
        ret.clear();
        if(root == NULL) return ret;
        int level = 0;
        while(!q.empty()) q.pop();
        q.push(new LNode(root,level));
        while(!q.empty()){
            LNode *node = q.front();
            q.pop();
            TreeNode *rt = node->rt;
            level = node->level;
            if(level >= ret.size()){//注意这里一定要先判断ret当前是否包含了level+1个vector,否则后面的ret[level]会RE
                vector<int> tmp;
                tmp.clear();
                ret.push_back(tmp);
            }
            ret[level].push_back(rt->val);
            
            if(rt->left != NULL)
                q.push(new LNode(rt->left,level+1));
            if(rt->right != NULL)
                q.push(new LNode(rt->right,level+1));
        }
        return ret;
    }
};
