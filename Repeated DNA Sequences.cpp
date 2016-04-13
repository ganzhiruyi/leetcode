class Solution {
public:
    /** A:1000001,C:1000011,G:1000111,T:1010100
    所以用后三位就可以了,然后10个字符映射到30bit的数,
    用一个hashmap记录，mp[key] = 0表示key没出现过,
    mp[key] = 1表示key出现了一次,mp[key] = 2表示key出现了2次
    **/
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        unordered_map<int,int> mp;
        int key = 0;
        for(int i = 0;i < s.length();++i){
            key = ((key<<3)|(s[i] & 0x7)) & (0x3fffffff);
            if(i < 9) continue;
            if(mp.find(key) == mp.end()) mp[key] = 1;
            else if(mp[key] == 1){
                ret.push_back(s.substr(i-9,10));
                mp[key] = 2;
            }
        }
        return ret;
    }
};
