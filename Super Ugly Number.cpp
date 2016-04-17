class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int cntPrimes = primes.size();
        int minUglyNum,minIdx;
        vector<int> idxs(cntPrimes,0);
        vector<int> uglyNum;
        uglyNum.push_back(1);
        while(uglyNum.size() < n){
            minUglyNum = INT_MAX,minIdx = 0;
            for(int i = 0;i < cntPrimes;++i){
                if(minUglyNum > primes[i]*uglyNum[idxs[i]]){
                    minUglyNum = primes[i]*uglyNum[idxs[i]];
                    minIdx = i;
                }
            }
            if(uglyNum.empty()||minUglyNum>uglyNum.back())
                uglyNum.push_back(minUglyNum);
            ++idxs[minIdx];
        }
        return uglyNum.back();
    }
};
