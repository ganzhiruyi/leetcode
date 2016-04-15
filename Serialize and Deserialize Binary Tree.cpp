#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
public:
    string int2str(int x){
        stringstream ss;
        string ret;
        ss << x;
        ss >> ret;
        return ret;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret = "";
        if(!root) return "[]";
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *p;
        while(!q.empty()){
            p = q.front();
            q.pop();
            ret += (p ? int2str(p->val) : "#") + ",";
            if(p){ // 这里对p要进行判断
                q.push(p->left);
                q.push(p->right);
            }
        }
        // 去掉末尾的多余的#
        int i;
        for(i = ret.length()-1;i >= 0 && (ret[i]=='#'||ret[i]==',');--i);
        return "["+ret.substr(0,i+1)+"]"; // 最后ret[i]肯定是','，也去掉
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        data = data.substr(1,data.length()-2);
        if(!data.length()) return NULL;
        int n = data.length(),val = 0;
        int i;
        int symbol = 1; // 处理负数的情况
        for(i = 0;i < n && data[i] != ',';++i)
            if(data[i] == '-') symbol = -1;
            else val = val*10 + (data[i]-'0');
        if(i < n) ++i; // 后面还有数
        TreeNode *rt = new TreeNode(val*symbol);
        queue<TreeNode*> q;
        q.push(rt);
        while(!q.empty()){
            TreeNode *p = q.front();
            q.pop();
            if(i >= n) break; // 已经到了末尾
            if(p){
                // 计算左子树
                if(data[i] == '#'){
                    i += 2; // 跳过‘#’和‘,’
                }
                else{
                    val = 0,symbol = 1;
                    while(i < n && data[i] != ','){
                        if(data[i] == '-') symbol = -1;
                        else val = val*10 + (data[i]-'0');
                        ++i;
                    }
                    if(i < n) ++i;
                    p->left = new TreeNode(val*symbol);
                    q.push(p->left);
                }
                if(i >= n) break; // 已经到末尾
                // 计算右子树
                if(data[i] == '#'){
                    i += 2; // 跳过‘#’和‘,’
                }
                else{
                    val = 0,symbol = 1;
                    while(i < n && data[i] != ','){
                        if(data[i] == '-') symbol = -1;
                        else val = val*10 + (data[i]-'0');
                        ++i;
                    }
                    if(i < n) ++i;
                    p->right = new TreeNode(val*symbol);
                    q.push(p->right);
                }
            }
        }
        return rt;
    }
};
int main(){
    string s;
    while(cin >> s){
        Codec c;
        TreeNode *rt = c.deserialize(s);
        cout << c.serialize(rt) << endl;
    }
    return 0;
}

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
