class Solution {
public:
    stack<TreeNode*> st;
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        while(!st.empty()) st.pop();
        TreeNode *cur = root,*pre =NULL; // 用一个pre记录前一个输出节点
        while(cur || !st.empty()){
            while(cur){
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            if(!cur->right || cur->right == pre){
                ret.push_back(cur->val);
                st.pop();
                pre = cur;
                cur = NULL;
            }
            else{
                cur = cur->right;
            }
        }
        return ret;
    }
};
