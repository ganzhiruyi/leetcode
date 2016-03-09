class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int tmp,up = 1;
        vector<int> ret;
        for(int i = digits.size()-1;i >= 0;--i){
            tmp = digits[i] + up;
            ret.push_back(tmp%10);
            up = tmp/10;
        }
        if(up) ret.push_back(up);
        reverse(ret.begin(), ret.end());
        return ret;        
    }
};
