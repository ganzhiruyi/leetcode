class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(nRows == 1) return s;
        int len = s.size(),row = 1,delta;
        string *rowChar = new string[nRows+1];
        for(int i = 0;i < len;i++){
            if(row == 1) delta = 1;
            if(row == nRows) delta = -1;
            rowChar[row].push_back(s[i]); 
            row += delta;
        }
        string ret = "";
        for(int i = 1;i <= nRows;i++) ret += rowChar[i];
        return ret;
    }
};
