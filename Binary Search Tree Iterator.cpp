/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> st;
    TreeNode *cur;
    BSTIterator(TreeNode *root) {
        while(!st.empty()) st.pop();
        cur = root;
        while(cur){
            st.push(cur);
            cur = cur->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }

    /** @return the next smallest number */
    int next() {
        cur = st.top();
        st.pop();
        int ret = cur->val;
        cur = cur->right;
        while(cur){
            st.push(cur);
            cur = cur->left;
        }
        return ret;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
