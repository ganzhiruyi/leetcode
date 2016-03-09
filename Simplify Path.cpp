class Solution {
public:
    deque<string> st;
    string simplifyPath(string path) {
        if(path == "") return "";
        int ii,i = 0,n = path.length();
        while(i < n){
            if(path[i] == '/'){
                ii = ++i;
                while(i < n && path[i] != '/') ++i;
                if(ii < n && ii < i){ // 要加上ii<i，避免一直是"///"的情况
                    string tmp = path.substr(ii,i-ii);
                    if(tmp == ".");
                    else if(tmp == ".."){
                        if(!st.empty()) st.pop_back(); // 避免/..的情况,不能继续向上了
                    }
                    else st.push_back(tmp);
                }
            }
        }
        if(st.empty()) return "/"; // 如果st中没有元素，证明已经到根目录了
        string ret = "";
        while(!st.empty()){
            ret += "/" + st.front();
            st.pop_front();
        }
        return ret;
    }
};
