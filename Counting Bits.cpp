class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1,0);
        int maxpower2 = 0; // 表示当前最大的2的次方的数,0表示没有
        for(int i = 1;i <= num;++i){
            if(i&(i-1) == 0){
                maxpower2 = i;
                ret[i] = 1;
            }
            else{
                ret[i] = 1+ret[i-maxpower2];
            }
        }
        return ret;
    }
};
