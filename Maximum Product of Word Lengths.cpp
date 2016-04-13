class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> intForWords(words.size(),0);
        for(int i = 0;i < words.size();++i){
            for(int j = 0;j < words[i].length();++j)
                intForWords[i] |= (1<<words[i][j]-'a');
        }
        int ans = 0;
        for(int i = 0;i < words.size();++i)
            for(int j = i+1;j < words.size();++j)
                if((intForWords[i] & intForWords[j]) == 0){
                    int now = words[i].length()*words[j].length();
                    ans = max(ans,now);
                }
        return ans;
    }   
};
