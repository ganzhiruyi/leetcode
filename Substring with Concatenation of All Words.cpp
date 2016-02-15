#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int N = 2000005;
typedef pair<int,int> pii;
typedef long long ll;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(words.size() == 0) return vector<int>();
        map<string,int> word_count;
        int word_len = words[0].length(),word_num = words.size();
        for(int i = 0;i < word_num;++i)
            ++word_count[words[i]];
        int j;
        map<string,int> counting;
        vector<int> ans;
        int up = s.length()-word_num*word_len;
        for(int i = 0;i <= up;++i){ //这里直接将up替换成表达式隐形转换会出错，变成一个奇怪的数
            counting.clear();
            for(j = 0;j < word_num;++j){
                string word = s.substr(i+j*word_len,word_len);
                if(word_count.find(word) != word_count.end()){
                    ++counting[word];
                    if(counting[word] > word_count[word])
                        break;
                }
                else break;
            } // 因为for循环中保证了单词的出现次数不大于word_count,j==word_num保证了counting肯定和word_count一致
            if(j == word_num) ans.push_back(i); 

        }
        return ans;
    }
};
int main(){
    int n;
    Solution sol;
    while(~scanf("%d",&n)){
        vector<string> words;
        string s;
        for(int i = 0;i < n;i++){
            cin >> s;
            words.push_back(s);
        }
        cin >> s;
        vector<int> ans = sol.findSubstring(s,words);
        for(int i = 0;i < ans.size();i++)
            cout << ans[i] << " , ";
        cout << endl;
    }
    return 0;
}