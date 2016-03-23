class Solution {
public:
    bool isUgly(int num) {
        if(num == 0) return false; // 0要特殊处理
        int factors[] = {2,3,5};
        for(int i = 0;i < 3;++i){
            while(num != 1 && num%factors[i]==0){
                num /= factors[i];
            }
        }
        return num==1;
    }
};
