/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct Node{
    TreeNode *rt;
    int level;
    Node(TreeNode *rt,int level) : rt(rt),level(level){}
};
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> ret,ans;
        ret.clear();
        if(root == NULL) return ret;
        queue<Node*> q;
        while(!q.empty()) q.pop();
        int level = 0;
        q.push(new Node(root,level));
        while(!q.empty()){
            Node *node = q.front();
            q.pop();
            TreeNode *rt = node->rt;
            level = node->level;
            if(level >= ret.size()){
                vector<int> tmp;
                tmp.clear();
                ret.push_back(tmp);
            }
            ret[level].push_back(rt->val);
            if(rt->left!=NULL) q.push(new Node(rt->left,level+1));
            if(rt->right!=NULL) q.push(new Node(rt->right,level+1));
        }
        for(int i = ret.size()-1;i>=0;i--) ans.push_back(ret[i]);
        return ans;
    }
};
