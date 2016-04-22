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
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length(),m = needle.length();
        if(!m) return 0;
        int next[m+1],i = 0,j = 0;
        get_next(needle,next);
        while(i < n){
            if(haystack[i]==needle[j]){
                ++i,++j;
                if(j == m) return i-m;
            }
            else if(j) j = next[j-1];
            else ++i;
        }
        return -1;
    }
    void get_next(string T,int next[]){
        int m = T.length();
        int j = 0,i = 1;
        next[0] = 0;
        while(i < m){
            if(T[i] == T[j]){
                next[i] = next[j]+1;
                ++i,++j;
            }
            else if(j) j = next[j-1];
            else next[i++] = 0;
        }
    }
};
