class Solution {
public:
    stack<TreeNode*> st;
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        TreeNode *cur = root;
        st.push(cur);
        while(!st.empty()){
            cur = st.top();
            st.pop();
            ret.push_back(cur->val);
            if(cur->right) st.push(cur->right);
            if(cur->left) st.push(cur->left);
        }
        return ret;
    }
};
