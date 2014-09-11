class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int n,m,i,j;
        n = strlen(haystack),m = strlen(needle), i = j = 0;
        if(n >= 0 && m == 0) return haystack;
        int *next = new int[m];
        get_next(needle,next);
        while(i < n && j < m){
            if(haystack[i] == needle[j]){
                i++,j++;
                if(j == m){
                    delete[] next;
                    return haystack+(i-m);
                }
            }
            else if(j == 0) i++;
            else j = next[j-1]+1;
        }
        delete[] next;
        return NULL;   
    }
    void get_next(char *T, int *next){
        next[0] = -1;
        int i,j,len;
        len = strlen(T);
        for(int i = 1;i < len;i++){
            j = next[i-1];
            while(j >= 0 && T[i] != T[j+1]) j = next[j];
            if(T[i] == T[j+1]) next[i] = j+1;
            else next[i] = -1;
        }
    }
};
