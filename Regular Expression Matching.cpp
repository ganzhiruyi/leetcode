#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
using namespace std;
bool isMatch(char* s, char* p) {
    if(*p == '\0') return *s == '\0';
    if(*(p+1) == '*'){
    	while(*p == *s || (*p == '.' && *s != '\0')){
    		if(isMatch(s++,p+2)) return true;
    	}
    	return isMatch(s,p+2);
    }
    else{
    	if(*p == *s || (*p == '.' && *s != '\0'))
    		return isMatch(s+1,p+1);
    	else return false;
    }
}
char s[100],p[100];
int main(){
	while(~scanf("%s %s",s,p)){
		printf("isMatch: %d\n", isMatch(s,p));
	}
	return 0;
}