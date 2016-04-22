class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size()) return "";
        string ret = "";
        int k = 0;
        while(k < strs[0].length()){
            for(int i = 1;i < strs.size();++i){
                if(k == strs[i].length()) return ret;
                if(strs[i][k] != strs[0][k]) return ret;
            }
            ret += strs[0][k];
            k++;
        }
        return ret;
    }
};
