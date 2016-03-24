class Solution {
public:
    string int2str(int x){
        stringstream ss;
        ss << x;
        string s;
        ss >> s;
        return s;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if(root == NULL) return ret;
        if(!root->left && !root->right){
            ret.push_back(int2str(root->val));
            return ret;
        }
        if(root->left){
            ret = binaryTreePaths(root->left);
            for(int i = 0;i < ret.size();++i){
                string s = int2str(root->val)+"->";
                ret[i] = s + ret[i];
            }
        }
        if(root->right){
            vector<string> tmp = binaryTreePaths(root->right);
            for(int i = 0;i < tmp.size();++i){
                string s = int2str(root->val)+"->";
                ret.push_back(s+tmp[i]);
            }
        }
        return ret;
    }
};
