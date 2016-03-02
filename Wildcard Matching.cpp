// 版本1：TLE
bool isMatch(char* s, char* p) {
    if(*s == '\0'){
        return *p=='\0' || *p == '*';
    }
    if(*p == '?') return isMatch(++s,++p);
    else if(*p == '*'){
        while(*(++p) == '*'); // 找到下一个不为"*"的模式串的字符*p
        for(;*s != '\0';++s)  // 遍历决定s中第几个字符和*p匹配,即决定‘*’匹配几个字符
            if(isMatch(s,p)) return true;
        return isMatch(s,p);
    }
    else{
        if(*p == *s) return isMatch(++s,++p);
        return false;
    }
}
// 版本二 12ms
bool isMatch(char* s, char* p) {
    char *prep = NULL,*pres = NULL;
    bool find = false; // 是否已经在p中找到'*'
    while(*s){
        if(*p == '?'){
            ++s;
            ++p;
        }
        else if(*p == '*'){
            prep = ++p; // prep保留*之后的第一个字符位置
            pres = s;   // pres保留p取到*时s所在的位置
            find = true;
        }
        else{
            if(*p == *s){
                ++p;
                ++s;
            }
            else if(find){
                p = prep;    // 如果不匹配就让p退到prep的位置，s退到pres+1的位置重新匹配，
                s = ++pres;  // 即让原来的pres位置直接和'*'匹配
            }
            else return false;
        }
    }
    while(*p == '*') ++p; //末尾可能存在多余的'*'，直接跳过
    return *p == '\0';
}
