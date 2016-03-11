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
// 非递归版本
class Solution {
public:
    stack<TreeNode*> st;
    vector<int> inorderTraversal(TreeNode* root) {
        while(!st.empty()) st.pop();
        vector<int> ret;
        if(root == NULL) return ret;
        TreeNode *cur = root;
        while(cur || !st.empty()){
            while(cur){ // 先一直往左走
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            ret.push_back(cur->val);
            cur = cur->right;            
        }
        return ret;
    }
};

