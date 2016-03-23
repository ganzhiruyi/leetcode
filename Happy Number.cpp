class Solution {
public:
    int sum2(int x){
        int ret = 0;
        while(x){
            ret += (x%10)*(x%10);
            x /= 10;
        }
        return ret;
    }
    bool isHappy(int n) {
        /** 这段注释代码用于找出1-9中的Happy number,有1,7两个数
        int isok[10];
        map<int,int> mp;
        for(int i = 1;i <= 9;++i){
            mp.clear();
            isok[i] = 0;
            int k = i;
            while(k != 1){
                if(mp.find(k) == mp.end()){
                    mp[k] = 1;
                }
                else break;
                k = sum2(k);
            }
            if(k == 1) isok[i] = 1;
        }
        for(int i = 0;i < 10;++i) cout << i << ": " << isok[i] << endl;
        **/
        while(n > 9){
            n = sum2(n);
        }
        return n==1 || n==7;
    }
};
