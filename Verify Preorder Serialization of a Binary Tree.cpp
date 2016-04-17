class Solution {
public:
    bool isValidSerialization(string &preorder) {
        int n = preorder.length();
        if(!n || (preorder[0]=='#' && n>1))
            return false;
        if(preorder[0]=='#' && n==1) return true;
        bool findLeaf = false;
        int i = 0,leafStart = 0,leafEnd = 0;
        while(i < n){
            if(preorder[i]=='#'){
                i += 2; // 跳过"#,"
                if(i >= n) return false;
                if(preorder[i]=='#'){
                    findLeaf = true;
                    leafEnd = i;
                    i += 2;
                    break;
                }
            }
            else{
                leafStart = i;
                while(i<n&&preorder[i]!=',') ++i;
                if(i < n) ++i; // 跳过','
            }
        }
        if(findLeaf){
            string newPreorder = preorder.substr(0,leafStart)
            +"#"+preorder.substr(leafEnd+1,n-leafEnd-1);
            return isValidSerialization(newPreorder);
        }
        return false;
    }
};
// 利用栈来完成
class Solution {
public:
    bool isValidSerialization(string &preorder) {
        int n = preorder.length();
        if(!n || (preorder[0]=='#' && n>1))
            return false;
        if(preorder[0]=='#' && n==1) return true;
        stack<string> st;
        int start,i = 0;
        while(i < n){
            start = i;
            while(i<n && preorder[i]!=','){
                ++i;
            }
            st.push(preorder.substr(start,i-start));
            i += 1; // 跳过","
            while(st.size() >= 3){
                bool findLeaf = false;
                if(st.top()=="#"){
                    string top1 = st.top();
                    st.pop();
                    if(st.top()=="#"){
                        st.pop();
                        // 除了最后任何时候栈顶元素都不能是"#"
                        if(st.size()==1 && st.top()=='#')
                            return false;
                        st.pop();
                        findLeaf = true;
                        st.push("#");
                    }
                    else st.push(top1);    
                }
                if(!findLeaf) break;
            }
        }
        return st.size()==1 && st.top()=="#";
    }
};
