#include <bits/stdc++.h>
using namespace std;
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode* next[26];
    bool isWord;
    TrieNode() {
        isWord = false;
        memset(next,NULL,sizeof(next));
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        int idx,i = 0,n = word.length();
        TrieNode *p = root;
        while(i < n){
            idx = word[i]-'a';
            if(!p->next[idx]) p->next[idx] = new TrieNode();
            p = p->next[idx];
            ++i;
        }
        p->isWord = true;
    }
    bool find(TrieNode *rt,string word){
        TrieNode *p = rt;
        int idx,i = 0,n = word.length();
        while(i < n){
            if(word[i] == '.'){
                for(int j = 0;j < 26;++j){
                    if(!p->next[j]) continue;
                    // 这里不要写p=p->next[j],不然j第二次循环就不是原来的p了;
                    if(i == n-1 && p->next[j]->isWord) return true; // word的末尾是'.'且p是单词节点
                    if(find(p->next[j],word.substr(i+1,n-i-1))) return true;
                }
                return false;
            }
            else{
                idx = word[i]-'a';
                if(!p->next[idx]) return false;
                p = p->next[idx];
                ++i;
            }
        }
        return p->isWord;
    }
    bool search(string word){
        return find(root,word);
    }
private:
    TrieNode* root;
};
class WordDictionary {
public:
    Trie trie;
    WordDictionary(){
        trie = Trie();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        trie.insert(word);
    }
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return trie.search(word);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
