class Solution {
public:
    bool isVowel(char ch){
        char vowels[] = {'A','E','I','O','U','a','e','i','o','u'};
        return binary_search(vowels,vowels+10,ch);
    }
    string reverseVowels(string s) {
        string vowels = "";
        for(int i = 0;i < s.length();++i)
            if(isVowel(s[i])) vowels += s[i];
        string ret = "";
        int k = vowels.length()-1;
        for(int i = 0;i < s.length();++i)
            if(isVowel(s[i])) ret += vowels[k--];
            else ret += s[i];
        return ret; 
    }
};
